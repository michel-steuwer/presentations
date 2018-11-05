#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <assert.h>

void * PrintHelloWorld(void* arg) {
    (void)arg;
    printf("Hello World from a thread!\n");
    return NULL;
}

int main() {
    pthread_t thread;

    int error = pthread_create(&thread, NULL, PrintHelloWorld, NULL);
    assert(error == 0);
    printf("Created thread\n");

    error = pthread_join(thread, NULL);
    if (error != 0) {
        printf("ERROR joining: %d\n", error);
        exit(-1);
    }
}

