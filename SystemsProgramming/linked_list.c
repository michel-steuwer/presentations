#include <stdio.h>

struct node {
  int value;
  struct node * next;
};

int main() {
  struct node c = {3, NULL};
  struct node b = {2, &c};
  struct node a = {1, &b};

  struct node * ptr = &a;
  while (ptr) {
    printf("%d\n", ptr->value);
    ptr = ptr->next;
  }
}
