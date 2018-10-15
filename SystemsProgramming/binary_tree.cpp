#include <stdio.h>
#include <stdlib.h>

struct node {
  const void * value_ptr;
  struct node * left_child;
  struct node * right_child;

  node(const void * value_ptr) {
      this->value_ptr = value_ptr;
      this->left_child = NULL;
      this->right_child = NULL;
  }

  void add_left_child(const void* value_ptr) {
    if (this->left_child) free(this->left_child);
    this->left_child = (struct node *)malloc(sizeof(struct node));
    if (this->left_child) {
      this->left_child->value_ptr = value_ptr;
      this->left_child->left_child = NULL;
      this->left_child->right_child = NULL;
    }
  }

  void add_right_child(const void* value_ptr) {
    if (this->right_child) free(right_child);
    this->right_child = (struct node *)malloc(sizeof(struct node));
    if (this->right_child) {
      this->right_child->value_ptr = value_ptr;
      this->right_child->left_child = NULL;
      this->right_child->right_child = NULL;
    }
  }

  ~node() {
    free(this->left_child);
    free(this->right_child);
  }
};

typedef struct node node;

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
  node root = node("b");
  root.add_left_child("a");
  root.add_right_child("c");
  root.right_child->add_left_child("d");
  root.right_child->add_right_child("e");
  print(&root, print_string);
}