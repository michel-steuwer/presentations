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

struct list {
  struct node * head;
  pthread_mutex_t mutex;
};

struct list* create_list(struct node* head) {
  if (!head) return NULL;
  struct list* ptr = malloc(sizeof(struct list));
  ptr->head = head;
  int error = pthread_mutex_init(&ptr->mutex, NULL);
  assert(error == 0);
  return ptr;
}

void free_list(struct list* list) {
  if (!list || !list->head) return;
  pthread_mutex_lock(&list->mutex);
  struct node* ptr = list->head;
  while(ptr->next) {
    struct node* n = ptr;
    ptr = ptr->next;
    free(n);
  }
  free(ptr);
  list->head = NULL;
  pthread_mutex_unlock(&list->mutex);
  int error = pthread_mutex_destroy(&list->mutex);
  assert(error == 0);
  free(list);
}

void append_to_list(struct list* list, struct node* n) {
  if (!list || !list->head) return;
  pthread_mutex_lock(&list->mutex);
  struct node * ptr = list->head;
  while(ptr->next) { ptr = ptr->next; }
  ptr->next = n;
  pthread_mutex_unlock(&list->mutex);
}

struct node* remove_from_list(struct list* list, int position) {
  if (!list || !list->head) return NULL;
  pthread_mutex_lock(&list->mutex);
  struct node* prev = list->head;
  while(position > 1 && prev->next) {
    prev = prev->next;
    position--;
  }
  if (position != 1) { return NULL; }
  struct node* to_be_removed = prev->next;
  prev->next = to_be_removed->next;
  pthread_mutex_unlock(&list->mutex);
  return to_be_removed;
}

void* do_remove_second_element_from_list(void* arg) {
  struct list* list = (struct list*)arg;
  free( remove_from_list(list, 1) );
  return NULL;
}

int main() {
  struct list* list = create_list(create_node('a'));
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

  struct node* ptr = list->head;
  while (ptr) {
    printf("%c", ptr->value);
    ptr = ptr->next;
    if (ptr) { printf(" -> "); }
  }
  printf("\n");

  free_list(list);
}
