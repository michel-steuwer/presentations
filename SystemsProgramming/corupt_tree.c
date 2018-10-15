#include <stdio.h> 
#include <stdlib.h>

struct node {
  const void * value_ptr;
  struct node * left_child;
  struct node * right_child;
};

typedef struct node node;

node * create_tree(const void * value_ptr,
                   node * left_child,
                   node * right_child) {
  node * root = malloc(sizeof(node));
  if (root) {
    root->value_ptr = value_ptr;
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

// void print(node * root) {
//   if (root) {
//     if (root->value) {
//       printf("%s\n", root->value);
//       print(root->left_child);
//       print(root->right_child);
//     }
//   }
// }

void print_string(const void * value_ptr) {
  const char * string = value_ptr; // by changing the type we give the bits again meaning
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
  node * a = create_tree("a", NULL, NULL);
  node * root = create_tree("b",
    a,
    create_tree("c",
      create_tree("d", NULL, NULL),
      create_tree("e", NULL, NULL)
      )
    );

  print(root, print_string);

  destroy_tree(a);

  print(root, print_string);

  destroy_tree(root);
}
