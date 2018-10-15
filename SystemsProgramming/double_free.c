#include <stdlib.h>

int main() {
  void * ptr1 = malloc(sizeof(int));
  void * ptr2 = ptr1;
  free(ptr1);
  ptr1 = NULL;
  free(ptr1);
  free(ptr2); // *** error for object 0x7f9355c00690: pointer being freed was not allocated
}