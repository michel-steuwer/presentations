#include <stdio.h>

float* search(float needle, float haystack[], int haystack_size) {
    for (int i = 0; i < haystack_size; i++) {
        if (needle == haystack[i]) { return &haystack[i]; }
    }
    return NULL;
}

int main() {
  float haystack[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  float needle = 15;

  float* ptr = search(needle, haystack, 9);
  if (ptr) {
    printf("%f\n", *ptr);
  } else {
    printf("%f not found in the array\n", needle);
  }
}