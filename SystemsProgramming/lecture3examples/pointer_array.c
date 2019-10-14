#include <stdio.h>

int main() {
  int vector[6] = {1, 2, 3, 4, 5, 6};
  int * ptr = vector;

  printf("4th element: %d\n", *(vector + 3));
  printf("5th element: %d\n", ptr[4]);

  printf("%ld\n", sizeof(vector));
  printf("%ld\n", sizeof(ptr));

  //int another_vector[6] = {1, 2, 3, 4, 5, 6};
  // vector = another_vector; // error: array type 'int [6]' is not assignable
}