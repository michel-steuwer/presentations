#include <stdio.h>

void foo() {
}

int main() {
  int x = 41;
  x = x + 1;

  foo();

  printf("%d \n", x);
}
