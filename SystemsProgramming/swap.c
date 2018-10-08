#include <stdio.h>

  void swap(void *x, void *y, size_t l) {
    char *a = x, *b = y, tmp;
    while(l--) {
       tmp  = *a;
       *a = *b;
       *b = tmp;
       a++;
       b++;
    }
  }

int main() {
    {
      int x = 23;
      float y = 42;

      swap(&x, &y, sizeof(int));

      printf("x = %d\n", x);
      printf("y = %f\n", y);
    }

    int x = 23;
    int y = 42;

    swap(&x, &y, sizeof(int));

    printf("x = %d\n", x);
    printf("y = %d\n", y);

    float fx = 23;
    float fy = 42;

    swap(&fx, &fy, sizeof(float));

    printf("fx = %f\n", fx);
    printf("fy = %f\n", fy);

}
