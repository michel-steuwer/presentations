#include <stdio.h>

#include <list>
#include <thread>
#include <mutex>
#include <optional>

struct safe_list {
private:
  std::list<int> list;
  std::mutex m;
public:
  void push_back(int i) {
    std::unique_lock<std::mutex> l(m);
    list.push_back(i);
  }

  std::optional<int> pop_front() {
    std::unique_lock<std::mutex> l(m);
    if (list.size() > 0) {
      auto item = list.front();
      list.pop_front();
      return item;
    } else {
      return {};
    }
  }
};

int main() {
  safe_list list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(4);
  list.push_back(5);
  list.push_back(6);

  auto item = list.pop_front();
  while ( item.has_value() ) {
    printf("%d\n", item.value());
    item = list.pop_front();
  }
}