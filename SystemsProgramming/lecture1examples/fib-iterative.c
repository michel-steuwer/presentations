#include <stdio.h>

int fib_while(int x) {
  int xnow = 0;
  int xnext = 1;

  while (x > 1) {
    int xtmp = xnow + xnext;
    xnow = xnext;
    xnext = xtmp;
    x = x - 1;
  }
  return xnext;
}

int fib_for(int x) {
  int xnow = 0;
  int xnext = 1;

  for (; x > 1; x = x -1) {
    int xtmp = xnow + xnext;
    xnow = xnext;
    xnext = xtmp;
  }
  return xnext;
}

int main() {
  //printf("fib(%d) = %d\n", 6, fib_while(6));
  printf("fib(%d) = %d\n", 100, fib_for(100));
}

