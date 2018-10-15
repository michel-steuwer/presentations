#include <stdio.h>

int fib(int x, int x1, int x2) {
    if (x == 0) {
        return x2;
    } else {
        return fib(x - 1, x1 + x2, x1);
    }
}

int fib(int x) {
    return fib(x, 0, 1);
}

int main() {
    int fib_6 = fib(6);
    printf("fib(6) = %d\n", fib_6);
}
