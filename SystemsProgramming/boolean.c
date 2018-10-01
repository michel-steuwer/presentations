#include <stdio.h>
#include <stdbool.h>

void foo() {
    bool a = true; bool b = false; bool c = a && b; printf("%d\n", c);
}

int main() {
  int i = 5;
  while (i) {
      i = i - 1;
      printf("%d\n", i);
  }
  printf("done\n");

  foo();
}