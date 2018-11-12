#include <stdio.h>
#include <future>
#include <vector>

int fib(int x, int x1, int x2) {
    if (x == 0) {
        return x2;
    } else {
        return fib(x - 1, x1 + x2, x1);
    }
}

int fib(int x) {
    return fib(x, 0, 1);
}

int main() {
  auto fs = std::vector<std::future<int>>();
  for (int i = 0; i < 10; i++) {
    fs.push_back( std::async([i] { return fib(i+1); }) );
  }
  // ...
  for (int i = 0; i < 10; i++) { printf("fib(%d) = %d\n", i+1, fs[i].get()); }
}