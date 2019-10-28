#include <stdlib.h>

struct node {
  const char * value;
  struct node * left_child;
  struct node * right_child;
};

typedef struct node node;

node * create_tree(const char * value, node* left_child, node * right_child) {
  node * root = malloc(sizeof(node));
  if (root) {
    root->value = value;
    root->left_child = left_child;
    root->right_child = right_child;
  }
  return root;
}

void destroy_tree(node * root) {
  if (root) {
    destroy_tree(root->left_child);
    destroy_tree(root->right_child);
    free( root );
  }
}

int main() {
  node * root = create_tree("b",
    create_tree("a", NULL, NULL),
    create_tree("c",
      create_tree("d", NULL, NULL),
      create_tree("e", NULL, NULL))
    );

  destroy_tree(root);
}