#include <stdio.h>
#include <future>

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
  auto task = std::async([] { return fib(6); });
  auto f7 = fib(7);
  printf("fib(7) = %d\n", f7);
  printf("fib(6) = %d (computed asynchronously)\n", task.get());
}