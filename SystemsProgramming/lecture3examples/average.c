#include <stdio.h>

float average(float array[], int size) {
  float sum = 0.0f;
  for (int i = 0; i < size; i++) { sum += array[i]; }
  return sum / size;
}

int main() {
  float array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  printf("%f\n", average(array, 9));
}
