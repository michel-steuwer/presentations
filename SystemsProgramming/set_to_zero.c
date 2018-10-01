#include <stdio.h>

void set_to_zero(int x) { x = 0; }

int main() {
    int y = 42;
    set_to_zero(y);
    printf("%d\n", y); // what will be printed?
}