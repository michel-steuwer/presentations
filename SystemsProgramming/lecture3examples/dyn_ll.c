#include <stdlib.h>
#include <stdio.h>

struct node {
  char value;
  struct node* next;
};

struct node* create_node(char value) {
  struct node* node_ptr = malloc(sizeof(struct node));
  if (node_ptr) {
    node_ptr->value = value;
    node_ptr->next = NULL;
  }
  return node_ptr;
}

void add_node_to_list(struct node* list, struct node* node) {
  if (!list) return;
  while (list->next) { list = list->next; }
  list->next = node;
}

void free_list(struct node* list) {
  if (!list) return;
  while (list->next) {
    struct node* head = list;
    list = list->next;
    free(head);
  }
}

int main() {
  struct node* a = create_node('a');
  struct node* b = create_node('b');
  struct node* c = create_node('c');
  add_node_to_list(a, b);
  add_node_to_list(a, c);

  struct node * ptr = a;
  while (ptr) {
    printf("%c -> ", (*ptr).value);
    ptr = (*ptr).next;
  }

  free_list(a);
}