#include <stdlib.h>
#include <stdio.h>

struct ints_on_the_heap { 
  int * ptr;

  ints_on_the_heap(int size) {
    ptr = (int*)malloc(sizeof(int) * size);
  }

  ~ints_on_the_heap() { free(ptr); }
};
typedef struct ints_on_the_heap ints_on_the_heap;

int main() {
  ints_on_the_heap i(23);
  i.ptr[22] = 42;

  printf("%d\n", i.ptr[22]);
}
