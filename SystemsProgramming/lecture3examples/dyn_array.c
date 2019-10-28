#include <stdlib.h>
#include <stdio.h>

int main() {
  printf("How many numbers do you want to average?\n");
  int count;
  if (scanf("%d", &count) == EOF) { exit(-1); }
  // allocate memory based on input
  int* array = malloc(count * sizeof(int));
  for (int i = 0; i < count; i++) {
    if (scanf("%d", array + i) == EOF) { exit(-1); }
  }

  float sum = 0.0f;
  for (int i = 0; i < count; i++) { sum += array[i]; }
  printf("The average is %.2f\n", sum / count);
  free(array);
}