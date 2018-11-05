#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <assert.h>

#include <unistd.h>

int randInt() {
    return (rand() % 50) + 50;
}

struct BoundedBuffer {
  int start;
  int end;
  int size;
  int* buffer;
  pthread_mutex_t m;
  pthread_cond_t add;
  pthread_cond_t remove;
};

typedef struct BoundedBuffer BoundedBuffer;

BoundedBuffer * createBoundedBuffer(int size) {
  if (size < 1) return NULL;
  BoundedBuffer * bb = malloc(sizeof(BoundedBuffer));
  if (bb) {
    bb->start = 0;
    bb->end = size-1;
    bb->size = size;
    bb->buffer = malloc(sizeof(int) * size);
    if (!bb->buffer) {
      free(bb);
      return NULL;
    }
    int err = pthread_mutex_init(&bb->m, NULL); assert(!err);
    err = pthread_cond_init(&bb->add, NULL); assert(!err);
    err = pthread_cond_init(&bb->remove, NULL); assert(!err);
  }
  return bb;
}

void destroyBoundedBuffer(BoundedBuffer * bb) {
  if (!bb) return;
  pthread_mutex_destroy(&bb->m);
  pthread_cond_destroy(&bb->add);
  pthread_cond_destroy(&bb->remove);
  free(bb->buffer);
  free(bb);
}

void addItem(BoundedBuffer * bb, int item) {
  if (!bb) return;
  pthread_mutex_lock(&bb->m);
  while (bb->start == bb->end) { // buffer is full
    printf("== Buffer is full ==\n");
    pthread_cond_wait(&bb->add, &bb->m);
  }
  // buffer is no longer full:
  // bb->start != bb->end
  bb->buffer[bb->start] = item;
  bb->start = (bb->start + 1) % bb->size; // move start one forward

  pthread_mutex_unlock(&bb->m);
  pthread_cond_signal(&bb->remove);
}

int removeItem(BoundedBuffer * bb) {
  if (!bb) assert(0);
  pthread_mutex_lock(&bb->m);
  while ( ((bb->end + 1) % bb->size) == bb->start ) { // buffer is empty
    printf("== Buffer is empty ==\n");
    pthread_cond_wait(&bb->remove, &bb->m);
  }
  // buffer is no longer empty
  bb->end = (bb->end + 1) % bb->size; // move end one forward
  int item = bb->buffer[bb->end];
  pthread_mutex_unlock(&bb->m);
  pthread_cond_signal(&bb->add);
  return item;
}

void * producer(void * arg) {
  BoundedBuffer * bb = (BoundedBuffer*)arg;

  for (int i = 0; i < 10; i++) {
    int item = randInt();
    printf("produced item %d\n", item);
    addItem(bb, item);
    usleep(randInt());
  }
  return NULL;
}

void * consumer(void * arg) {
  BoundedBuffer * bb = (BoundedBuffer*)arg;

  for (int i = 0; i < 10; i++) {
    int item = removeItem(bb);
    printf("    consumed item %d\n", item);
    usleep(randInt());
  }
  return NULL;
}

int main() {
    srand(time(NULL));
    pthread_t t1;
    pthread_t t2;
    int err;

    BoundedBuffer * bb = createBoundedBuffer(4);

    err = pthread_create(&t1, NULL, consumer, bb); assert(err == 0);
    err = pthread_create(&t2, NULL, producer, bb); assert(err == 0);

    err = pthread_join(t1, NULL); assert(err == 0);
    err = pthread_join(t2, NULL); assert(err == 0);
}