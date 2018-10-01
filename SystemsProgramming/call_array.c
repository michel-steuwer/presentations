#include <stdio.h>

void foo(int array[]) {
  array[0] = 42;
}

int main() {
  int array[5] = {1, 2, 3, 4, 5};

  foo(array);

  for (int i = 0; i < 5; i++) {
    printf("%d\n", array[i]);
  }
}