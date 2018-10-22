#include <stdio.h>
#include <stdlib.h>

struct node {
  const void * value_ptr;
  struct node * left_child;
  struct node * right_child;
};

typedef struct node node;


node * create_node(const void * value_ptr) {
    node * n = malloc(sizeof(node));
    n->value_ptr = value_ptr;
    n->left_child = NULL;
    n->right_child = NULL;
    return n;
}

  void add_left_child(node * n, const void* value_ptr) {
    if (n->left_child) free(n->left_child);
    n->left_child = malloc(sizeof(node));
    if (n->left_child) {
      n->left_child->value_ptr = value_ptr;
      n->left_child->left_child = NULL;
      n->left_child->right_child = NULL;
    }
  }

  void add_right_child(node * n, const void* value_ptr) {
    if (n->right_child) free(n->right_child);
    n->right_child = (struct node *)malloc(sizeof(struct node));
    if (n->right_child) {
      n->right_child->value_ptr = value_ptr;
      n->right_child->left_child = NULL;
      n->right_child->right_child = NULL;
    }
  }

  void delete_node(node * n) {
    free(n->left_child);
    free(n->right_child);
    free(n);
  }

void print_string(const void * value_ptr) {
  const char * string = (const char*)value_ptr; // by changing the type we give the bits again meaning
  printf("%s\n", string);
}

void print(node * root, void (* print_function)(const void *) ) {
  if (root) {
    print_function(root->value_ptr);
    print(root->left_child, print_function);
    print(root->right_child, print_function);
  }
}

int main() {
  //   b    |
  //  / \   |
  // a  c   |
  //   / \  |
  //  d  e  |
  node* root = create_node("b");
  add_left_child(root, "a");
  add_right_child(root, "c");
  add_left_child(root->right_child, "d");
  add_right_child(root->right_child, "e");
  print(root, print_string);

  delete_node(root);
}