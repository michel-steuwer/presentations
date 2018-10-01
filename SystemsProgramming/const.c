#include <stdio.h>
#define PI 3.14

int foo() {
    const float pi = 3.14;

    printf("%f vs %f\n", PI, pi);
}

int main() {
 foo();
 foo();
}
