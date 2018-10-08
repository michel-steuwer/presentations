#include <stdio.h>

void print_next(int * ptr) {
  ptr++; if (ptr) { printf("%d\n", *ptr); }
}

int main() {
  int array[6] = {0, 1, 2, 3, 4, 5};
  print_next(&(array[2]));
}