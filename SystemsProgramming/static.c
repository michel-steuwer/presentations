#include <stdio.h>


int global_bad_here = 5; // static lifetime (entire program)

void foo() {
    static int count = 0;
    count++;
    printf("I have been called %d times\n", count);
    printf("%d\n", global_bad_here);
} // lifetime of count doesn't end here!

int main() {
    foo();
    foo();
    foo();
    foo();
    printf("%d\n", count);
}
