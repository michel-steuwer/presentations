#include <stdio.h>

int main() {
  int vector[6] = {1, 2, 3, 4, 5, 6};

  int * ptr = vector; // start at the beginning
  while (ptr <= &(vector[5])) {
    printf("%d ", *ptr); // print the element in the array
    ptr++; // go to the next element
  }
  printf("\n");
}