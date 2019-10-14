#include <stdio.h>

long diff(void* fst, void* snd) {
  return fst - snd;
}

int main() {
  int x = 42;
  int y = 23;
  printf("&x = %p\n", &x); // print the address of x
  printf("&y = %p\n", &y); // print the address of y
  printf("&x - &y = %ld\n", diff(&x, &y)); // print the difference between addresses

  // printf("%p\n", &42); // can not take the address of a temporary
}