#include <list>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <vector>

struct notification_queue {
private:
  std::list<std::function<void()>> q;
  std::mutex                       m;
  std::condition_variable          ready;
public:
  std::function<void()> pop() {
    std::unique_lock<std::mutex> lock(m);
    ready.wait(lock, [this]{ return !q.empty(); });
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
};


struct task_system {
private:
  const int                count = std::thread::hardware_concurrency();
  std::vector<std::thread> threads;
  notification_queue       q;

  void run(int i) {
    while (true) {
      auto f = q.pop();
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
}