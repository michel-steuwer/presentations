#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <assert.h>
#include <stdbool.h>

#include <unistd.h>

int randInt() {
    return (rand() % 50) + 50;
}

// std::condition_variable cv;
pthread_mutex_t m;

// shared state indicating if tea is ready
bool teaIsReady = false;
 
void *me(void* arg)
{
    (void)arg;
    printf("Me: Waiting for my tea ...\n");
    
    pthread_mutex_lock(&m);
    while (!teaIsReady) {
        pthread_mutex_unlock(&m);
        printf("Me: (Unamused) // do nothing\n");
        pthread_mutex_lock(&m);
    }
    pthread_mutex_unlock(&m);
    
    printf("Me: (Happy) ... finished waiting.\n");
    return NULL;
}
 
void *teaRobot(void* arg)
{
    (void) arg;
    printf("  Tea Robot: Making tea ...\n");
    
    usleep(randInt());
    
    pthread_mutex_lock(&m);
    teaIsReady = true;
    pthread_mutex_unlock(&m);
    
    printf("  Tea Robot: Done!\n");
    return NULL;
}




 
int main()
{
    srand(time(NULL));
    pthread_t t1;
    pthread_t t2;
    int err;

    err = pthread_mutex_init(&m, NULL); assert(err == 0);

    err = pthread_create(&t1, NULL, me, NULL);       assert(err == 0);
    err = pthread_create(&t2, NULL, teaRobot, NULL); assert(err == 0);

    err = pthread_join(t1, NULL); assert(err == 0);
    err = pthread_join(t2, NULL); assert(err == 0);

    err = pthread_mutex_destroy(&m); assert(err == 0);
}