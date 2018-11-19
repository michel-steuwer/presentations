#include <stdio.h>

#include <list>

int main() {
  std::list<int> list = {1, 2, 3, 4, 5, 6};

  while ( list.size() > 0 ) {
    auto item = list.front();
    list.pop_front();
    printf("%d\n", item);
  }
}