#include <stdio.h>
#include <stdlib.h>

struct node {
    const char * value;
    struct node * left_child;
    struct node * right_child;
};
typedef struct node node;

node * create_node(void * v, node * left, node * right) {
    node * n = malloc(sizeof(node));
    if (n) {
        n->value = v;
        n->left_child = left;
        n->right_child = right;
    }
    return n;
}

void delete_node(node * n) {
    if (n) {
        delete_node(n->left_child);
        delete_node(n->right_child);
        free(n);
    }
}

void print_char(const void * ptr) {
    const char * c_ptr = ptr;
    printf("%c\n", *c_ptr);
}

void print(node * n, void (* function_pointer)(const void *) ) {
    function_pointer(n->value);
    if (n->left_child)
        print(n->left_child, function_pointer);
    if (n->right_child)
        print(n->right_child, function_pointer);
}

int main() {
  //   b    |
  //  / \   |
  // a  c   |
  //   / \  |
  //  d  e  |
  char * data = malloc(sizeof(char));
  if (data) {
    *data = 'a';

    char b = 'b';
    int i = 42;
  node * root = create_node(&b,
          create_node(&b, NULL, NULL),
          create_node(&i,
            create_node(data, NULL, NULL),
            create_node(data, NULL, NULL)));

  print(root, print_char);

  delete_node(root);

  }
}

