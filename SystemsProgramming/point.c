#include <stdio.h>

struct point {
  int x;
  int y;
};

int main() {
    struct point p = {1, 2};
    printf("x = %d\ny = %d\n", p.x, p.y);
}
