#include <stdio.h>

int max(int lhs, int rhs);

int main() {
    int x = max(4.5, 'b');
    printf("%d\n", x);
    
}

int max(int lhs, int rhs) {
  if (lhs > rhs) { return lhs; } else { return rhs; }
}