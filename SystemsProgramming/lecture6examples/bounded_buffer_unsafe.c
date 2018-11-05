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
  }
  return bb;
}

void destroyBoundedBuffer(BoundedBuffer * bb) {
  if (!bb) return;
  free(bb->buffer);
  free(bb);
}

void addItem(BoundedBuffer * bb, int item) {
  if (!bb) return;
  bb->buffer[bb->start] = item;
  bb->start = (bb->start + 1) % bb->size; // move start one forward
}

int removeItem(BoundedBuffer * bb) {
  if (!bb) assert(0);
  // buffer is no longer empty
  bb->end = (bb->end + 1) % bb->size; // move end one forward
  int item = bb->buffer[bb->end];
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