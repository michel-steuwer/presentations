#include <list>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <vector>
#include <optional>
#include <chrono>

struct notification_queue {
private:
  std::list<std::function<void()>> q;
  bool                             done = false;
  std::mutex                       m;
  std::condition_variable          ready;
public:
  std::optional<std::function<void()>> pop() {
    std::unique_lock<std::mutex> lock(m);
    ready.wait(lock, [this]{ return (!q.empty()) || done; });
    if (q.empty()) return {};
    auto f = q.front();
    q.pop_front();
    return f;
  }

  void push(std::function<void()> f) {
    {
      std::unique_lock<std::mutex> lock(m);
      q.push_back(f);
    }
    ready.notify_one();
  }

  void setDone() {
    {
      std::unique_lock<std::mutex> lock(m);
      done = true;
    }
    ready.notify_all();
  }
};


struct task_system {
private:
  const int                count = std::thread::hardware_concurrency();
  std::vector<std::thread> threads;
  notification_queue       q;

  void run(int i) {
    while (true) {
      auto optional_f = q.pop();
      if (!optional_f.has_value()) return;
      auto f = optional_f.value();
      f();
    }
  }

public:
  task_system() {
    printf("Start task system with %d threads\n", count);
    for (auto n = 0; n != count; n++) {
      threads.emplace_back([this, n](){ run(n); });
    }
  }

  ~task_system() {
    q.setDone();
    for (auto n = 0; n != count; n++) {
      threads[n].join();
    }
  }

  void async(std::function<void()> f) {
    q.push(f);
  }
};


int main() {
  task_system t;

  t.async( [] { printf("Hello world\n"); } );
  t.async( [] { printf("Hello world\n"); } );
  t.async( [] { printf("Hello world\n"); } );
  t.async( [] { printf("Hello world\n"); } );
  t.async( [] { printf("Hello world\n"); } );

  using namespace std::chrono_literals;
  std::this_thread::sleep_for(2s);
}