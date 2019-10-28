#include <stdio.h>
#include <stdlib.h>
#include <memory>

struct node {
  const void * value_ptr;
  std::unique_ptr<struct node> left_child;
  std::unique_ptr<struct node> right_child;
  struct node * parent;

  node(const void * value_ptr) {
      this->value_ptr = value_ptr;
      this->left_child = NULL;
      this->right_child = NULL;
      this->parent = NULL;
  }

  void add_left_child(const void* value_ptr) {
    this->left_child = std::make_unique<node>(value_ptr);
    this->left_child->parent = this;
  }

  void add_right_child(const void* value_ptr) {
    this->right_child = std::make_unique<node>(value_ptr);
    this->right_child->parent = this;
  }

  ~node() {   }
};

typedef struct node node;

void print_string(const void * value_ptr) {
  const char * string = (const char*)value_ptr; // by changing the type we give the bits again meaning
  printf("%s\n", string);
}

void print(node * root, void (* print_function)(const void *) ) {
  if (root) {
    print_function(root->value_ptr);
    print(root->left_child.get(), print_function);
    print(root->right_child.get(), print_function);
  }
}

int main() {
  //   b    |
  //  / \   |
  // a  c   |
  //   / \  |
  //  d  e  |
  node root("b");
  root.add_left_child("a");
  root.add_right_child("c");
  root.right_child->add_left_child("d");
  root.right_child->add_right_child("e");
  print(&root, print_string);
}