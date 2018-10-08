#include <stdlib.h>
#include <stdio.h>

struct node {
  int value;
  struct node * next;
};

struct node* create_node(char value) {
  struct node * ptr = malloc(sizeof(struct node));
  ptr->value = value; ptr->next  = NULL;
  return ptr;
}

void add_node_to_list(struct node* list, struct node* node) {
  if (!list) return;
  while(list->next) { list = list->next; }
  list->next = node;
}

void free_list(struct node* list) {
  if (!list) return;
  while(list->next) {
    struct node* head = list;
    list = list->next;
    free(head);
  }
}

int main() {
  struct node* a = create_node('a');
  struct node* b = create_node('b');
  struct node* c = create_node('c');

  struct node* list = a;
  add_node_to_list(list, b);
  add_node_to_list(list, c);

  while (list) {
    printf("%c", list->value);
    list = list->next;
    if (list) { printf(" -> "); }
  }
  printf("\n");

  free_list(list);
}
