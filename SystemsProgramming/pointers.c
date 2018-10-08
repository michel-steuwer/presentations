#include <stdio.h>

void set_to_zero(int * ptr) {
    *ptr = 0;
}

int main() {

  int x = 42;
  printf("x = %d\n", x);
  printf("&x = %p\n", &x);
  int * pointer_to_x = &x;
  printf("value of pointer_to_x: %p\n", pointer_to_x);
  printf("sizeof pointer_to_x: %lu\n", sizeof(pointer_to_x));
  printf("*pointer_to_x = %d\n", *pointer_to_x);

  printf("&pointer_to_x = %p\n", &pointer_to_x);

  set_to_zero(&x);

  printf("x = %d\n", x);

}
