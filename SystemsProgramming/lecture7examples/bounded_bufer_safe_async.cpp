#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include <thread>
#include <vector>
#include <random>
#include <future>

int randInt() {
  static std::default_random_engine generator;
  static std::uniform_int_distribution<int> distribution(50,100);
  return distribution(generator);
}

struct BoundedBuffer {
private:
  int start;
  int end;
  int size;
  std::vector<int> buffer;
  std::mutex m;
  std::condition_variable add_cv;
  std::condition_variable remove_cv;

public:
  BoundedBuffer(int max_size) {
    start   = 0;
    end     = max_size-1;
    size    = max_size;
    buffer  = std::vector<int>(size);
  }

  void addItem(int item) {
    std::unique_lock<std::mutex> lock(m);
    add_cv.wait(lock, [this]{ return start != end; });

    buffer[start] = item;
    start = (start + 1) % size;
    remove_cv.notify_one();
  }

  int removeItem() {
    std::unique_lock<std::mutex> lock(m);
    remove_cv.wait(lock, [this]{ return ((end + 1) % size) != start; });

    end = (end + 1) % size;
    int item = buffer[end];
    add_cv.notify_one();
    return item;
  }
};

int main() {
    auto bb = BoundedBuffer{4};

    auto consumer = std::async([bb = &bb]{
      for (int i = 0; i < 10; i++) {
        int item = bb->removeItem();
        printf("    consumed item %d\n", item);
        std::this_thread::sleep_for(std::chrono::milliseconds(randInt()));
      }
      return "consumer done";
    });

    auto producer = std::async([bb = &bb]{
      for (int i = 0; i < 10; i++) {
        int item = randInt();
        printf("produced item %d\n", item);
        bb->addItem(item);
        std::this_thread::sleep_for(std::chrono::milliseconds(randInt()));
      }
      return "producer done";
    });

    printf("%s\n", consumer.get());
    printf("%s\n", producer.get());
}
