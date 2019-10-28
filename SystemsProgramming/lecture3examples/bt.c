#include <stdio.h>
#include <stdlib.h>

struct node {
  char value;
  struct node * left_child;
  struct node * right_child;
};

int main() {
  struct node c = {'c', NULL, NULL};
  struct node b = {'b', NULL, NULL};
  struct node a = {'a', &b, &c};
}
