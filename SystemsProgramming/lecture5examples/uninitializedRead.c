#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
  int* a = malloc(sizeof(int)*10);
  a[5] = 0;
  if (a[argc])
    printf("xx\n");
  return 0;
}