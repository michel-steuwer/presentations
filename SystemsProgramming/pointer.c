#include <stdio.h>

long diff(void* fst, void* snd) {
  return fst - snd;
}

int main() {
  int x = 42;
  int* ptr = &x;
  int* * ptr_to_ptr = &ptr;

  printf("&x = %p\n", &x);      // print the address of x
  printf("ptr = %p\n", ptr);      // print ptr
  printf("&ptr = %p\n", &ptr);  // print the address of ptr
  printf("&ptr_to_ptr = %p\n", &ptr_to_ptr);  // print the address of ptr_to_ptr

  int y = 23;
  ptr = &y;
  printf("&y = %p\n", &y);
  printf("ptr = %p\n", ptr);
}