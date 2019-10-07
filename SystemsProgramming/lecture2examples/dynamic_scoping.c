#include <stdio.h>

#define ADD_A(x) x + a

int add_one(int x) {
  int a = 1;
  return ADD_A(x);
}

int add_two(int x) {
  int a = 2;
  return ADD_A(x);
}

int main() {
  int x = 5;
  printf("%d\n", add_one(x));
  printf("%d\n", add_two(x));
}