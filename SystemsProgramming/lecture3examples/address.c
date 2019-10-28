#include <stdio.h>

int main () {
  int x = 42;
  int y = 23;
  printf("x = %d\n", x);
  int * p_x = &x;
  printf("address of x = %p\n", p_x);
  int * p_y = &y;
  printf("address of y = %p\n", p_y);

  printf("address of p_x = %p\n", &p_x);

  printf("value of x = %d\n", *p_x);
}
