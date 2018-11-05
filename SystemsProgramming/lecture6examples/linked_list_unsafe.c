#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <assert.h>

struct node {
  int value;
  struct node * next;
};

struct node* create_node(char value) {
  struct node * ptr = malloc(sizeof(struct node));
  ptr->value = value; ptr->next  = NULL;
  return ptr;
}

void free_list(struct node* list) {
  if (!list) return;
  while(list->next) {
    struct node* head = list;
    list = list->next;
    free(head);
  }
  free(list);
}

void append_to_list(struct node* list, struct node* n) {
  if (!list) return;
  while(list->next) { list = list->next; }
  list->next = n;
}

struct node* remove_from_list(struct node* list, int position) {
  if (!list) return NULL;
  struct node* prev = list;
  while(position > 1 && prev->next) {
    prev = prev->next;
    position--;
  }
  if (position != 1) { return NULL; }
  struct node* to_be_removed = prev->next;
  prev->next = to_be_removed->next;
  return to_be_removed;
}

void* do_remove_second_element_from_list(void* arg) {
  struct node* a = (struct node*)arg;
  free( remove_from_list(a, 1) );
  return NULL;
}

int main() {
  struct node* list = create_node('a');
  append_to_list(list, create_node('b'));
  append_to_list(list, create_node('c'));
  append_to_list(list, create_node('d'));

  pthread_t t1;
  pthread_t t2;
  int error;
  error = pthread_create(&t1, NULL, do_remove_second_element_from_list, list);
  assert(error == 0);
  error = pthread_create(&t2, NULL, do_remove_second_element_from_list, list);
  assert(error == 0);

  error = pthread_join(t1, NULL); assert(error == 0);
  error = pthread_join(t2, NULL); assert(error == 0);

  while (list) {
    printf("%c", list->value);
    list = list->next;
    if (list) { printf(" -> "); }
  }
  printf("\n");

  free_list(list);
}
