// a -> b -> c -> NULL

#include <stdio.h>
#include <stdlib.h>

struct node {
  char value;
  struct node* next;
};

int main() {
  struct node c = {'c', NULL};
  struct node b = {'b', &c};
  struct node a = {'a', &b};

  struct node * ptr = &a;
  while (ptr) {
    printf("%c -> ", (*ptr).value);
    ptr = (*ptr).next;
  }
}