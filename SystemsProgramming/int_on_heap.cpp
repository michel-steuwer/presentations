#include <stdlib.h>
#include <stdio.h>

struct int_on_the_heap { 
  int * int_ptr;

  int_on_the_heap(int value) {
    int_ptr = (int*)malloc(sizeof(int));
    if (int_ptr) { *int_ptr = value; }
  }

  //int_on_the_heap(int_on_the_heap&) = delete;

  ~int_on_the_heap() { free(int_ptr); }
};

void set_to_zero(int_on_the_heap * i) {
  *i->int_ptr = 0;
}

void print(int_on_the_heap* i) {
  printf("%d\n", *i->int_ptr);
}

int main() {
  int_on_the_heap i(42);
  
  set_to_zero(&i);

  print(&i);
}
