#include <stdio.h> 

struct node {
  int value;
  struct node * left_child;
  struct node * right_child;
};

typedef struct node node;

node * find(char value , node * root) {
  if (value == root->value) {
    return root;
  }
  if (value < root->value && root->left_child != NULL) {
    return find(value, root->left_child);
  }
  if (value > root->value && root->right_child != NULL) {
    return find(value, root->right_child);
  }
  return NULL;
}

int main() {
  //   b    |
  //  / \   |
  // a  c   |
  //   / \  |
  //  d  e  |
  node e = {55, NULL, NULL};
  node d = {44, NULL, NULL};
  node c = {33, &d, &e};
  node b = {22, NULL, NULL};
  node a = {11, &b, &c};

  node * root = &b;
  int value = 8;
  node * found = find(value, root);

  if (found) {
    printf("Found %d in the tree\n", found->value);
  } else {
    printf("%d not found in the tree\n", value);
  }
}
