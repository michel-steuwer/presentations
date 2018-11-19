#include <stdio.h>

#include <list>
#include <thread>
#include <mutex>

struct maybe_safe_list {
private:
  std::list<int> list;
  std::mutex m;
public:
  void push_back(int i) {
    std::unique_lock<std::mutex> l(m);
    list.push_back(i);
  }

  int size() {
    std::unique_lock<std::mutex> l(m);
    return list.size();
  }

  int pop_front() {
    std::unique_lock<std::mutex> l(m);
    auto item = list.front();
    list.pop_front();
    return item;
  }
};

int main() {
  maybe_safe_list list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(4);
  list.push_back(5);
  list.push_back(6);

  while ( list.size() > 0 ) {
    auto item = list.pop_front();
    printf("%d\n", item);
  }
}