#include <memory>

struct node {
  const void * value_ptr;
  // the parent owns both children uniquely
  std::unique_ptr<struct node> left_child;
  std::unique_ptr<struct node> right_child;
  // nodes do not have any ownership over their parents
  struct node* parent;

  node(const void * value) {
    value_ptr = value;
    left_child = NULL;
    right_child = NULL;
    parent = NULL;
  }

  ~node() { }

  void add_left_child(const void* value) {
    left_child = std::make_unique<struct node>(value);
    if (left_child) {
      left_child->parent = this;
    }
  }

  void add_left_child(std::unique_ptr<struct node> node) {
    left_child = std::move(node);
    if (left_child) {
      left_child->parent = this;
    }
  }

  void add_right_child(const void* value) {
    right_child = std::make_unique<struct node>(value);
    if (right_child) {
      right_child->parent = this;
    }
  }
};

int main() {
  struct node root("root");
  root.add_left_child("left");
  root.add_right_child("right");

  printf("root: %s\n", root.value_ptr);
  printf("left: %s\n", root.left_child->value_ptr);
  printf("right: %s\n", root.right_child->value_ptr);

  printf("root->left_child->parent: %s\n", root.left_child->parent->value_ptr);
}