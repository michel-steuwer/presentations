#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <assert.h>

void * PrintHelloWorld(void* arg) {
    int * int_arg = (int*) arg; // cast to assign meaning to the bits stored at *arg
    if (int_arg) {
      printf("Hello World %d!\n", *int_arg);
    }
    return int_arg;
}

int main() {
    pthread_t thread;

    int data = 42;
    printf("Address of data: %p\n", &data);

    int error = pthread_create(&thread, NULL, PrintHelloWorld, &data);
    assert(error == 0);
    printf("Created thread\n");

    int * return_value;
    error = pthread_join(thread, (void**)&return_value);
    if (error != 0) {
        printf("ERROR joining: %d\n", error);
        exit(-1);
    }

    if (return_value) {
      printf("Return value: %p (%d)\n", return_value, *return_value);
    }
}

