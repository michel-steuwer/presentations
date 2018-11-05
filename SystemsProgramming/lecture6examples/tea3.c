#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <assert.h>
#include <stdbool.h>

#include <unistd.h>

int randInt() {
    return (rand() % 50) + 50;
}

pthread_mutex_t m;
pthread_cond_t cv;

// shared state indicating if tea is ready
bool teaIsReady = false;
 
void *me(void* arg)
{
    (void)arg;
    pthread_mutex_lock(&m);
    while (!teaIsReady) {
        printf("Me: Waiting for my tea ...\n");
        pthread_cond_wait(&cv, &m);
    }
    
    printf("Me: (Happy) ... finished waiting.\n");
    printf("Me: Is the tea really finished? %s\n", teaIsReady ? "Yes" : "No");
    return NULL;
}
 
void *teaRobot(void* arg)
{
    (void) arg;
    printf("  Tea Robot: Making tea ...\n");

    pthread_cond_signal(&cv);
    printf("  Tea Robot: Almost done! ;-)\n");
    
    usleep(randInt());
    
    pthread_mutex_lock(&m);
    teaIsReady = true;
    pthread_mutex_unlock(&m);
    pthread_cond_signal(&cv);
    
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
    err = pthread_cond_init(&cv, NULL); assert(err == 0);

    err = pthread_create(&t1, NULL, me, NULL);       assert(err == 0);
    err = pthread_create(&t2, NULL, teaRobot, NULL); assert(err == 0);

    err = pthread_join(t1, NULL); assert(err == 0);
    err = pthread_join(t2, NULL); assert(err == 0);

    pthread_cond_destroy(&cv);
    pthread_mutex_destroy(&m);
}