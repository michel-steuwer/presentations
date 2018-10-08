#include <stdio.h>

int main() {
    int x[] = {1, 2, 3};
    int y[] = {1, 2, 3};

    int z = 0;
    for (int i = 0; i < 3; i++) {
        z += x[i] * y[i];
    }
    printf("%d\n", z);
    return 42;
}
