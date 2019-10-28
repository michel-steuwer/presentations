#include <stdlib.h>
#include <stdio.h>

struct ints_on_the_heap {
  int *ptr; // to the heap
  // constructor
  ints_on_the_heap(int size) {
    ptr = (int *) malloc(sizeof(int) * size);
    printf("%p = malloc(%d)\n", ptr, size);
  }
  // destructor
  ~ints_on_the_heap() {
    printf("free(%p)\n", ptr);
    free(ptr);
  }
};

int main() {
  ints_on_the_heap i(23);
  ints_on_the_heap j(42);
  
  i.ptr[0] = 42;
} // 