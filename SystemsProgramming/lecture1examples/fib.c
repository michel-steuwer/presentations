#include <stdio.h>

int _fib(int x, int x1, int x2) {
  if (x == 0) {
    return x2;
  } else {
    return _fib(x - 1, x1 + x2, x1);
  }
}

int fib(int x) {
  return _fib(x, 1, 0);
}

int main() {
  printf("fib(%d) = %d\n", 100, fib(100));
}

