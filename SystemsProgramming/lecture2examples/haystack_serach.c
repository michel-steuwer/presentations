#include <stdio.h>

typedef struct { int x; int y; } point;

int search(point needle, point haystack[], int haystack_size) {
    for (int i = 0; i < haystack_size; i++) {
        point candidate = haystack[i];
        if (needle.x == candidate.x && needle.y == candidate.y) { return i; }
    }
    return -1;
}

int main() {
  point ps[] = { {1, 2}, {2, 3}, {3, 4} };

  point p = {3, 5};

  printf("%d\n", search(p, ps, 3));
}