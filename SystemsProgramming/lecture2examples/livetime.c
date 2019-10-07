#include <stdio.h>


int foo() {
    static int count_calls_to_foo = 0;
    return ++count_calls_to_foo;
}

int main() {
    int x = 42;

    {
        int y = x + 1;
    } // end of lifetime for y


    printf("%d\n", foo());
    printf("%d\n", foo());
    printf("%d\n", foo());
    printf("%d\n", foo());
} // end of lifetime x
