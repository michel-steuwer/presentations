#include <stdio.h>

int main() {
  int x = 42;
  int * pointer_to_x = &x;
  printf("value of pointer_to_x: %p\n", pointer_to_x); // prints 0x77...
  printf("value of x: %d\n", *pointer_to_x);           // prints 42
}