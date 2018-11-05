#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <assert.h>
#include <stdbool.h>

#include <unistd.h>

int randInt() {
    return (rand() % 50) + 50;
}

// shared state indicating if tea is ready
bool teaIsReady = false;
 
void *me(void* arg)
{
    (void)arg;
    printf("Me: Waiting for my tea ...\n");
    
    while (!teaIsReady) {
        printf("Me: (Unamused) // do nothing\n");
    }
    
    printf("Me: (Happy) ... finished waiting.\n");
    return NULL;
}
 
void *teaRobot(void* arg)
{
    (void) arg;
    printf("  Tea Robot: Making tea ...\n");
    
    usleep(randInt());
    
    teaIsReady = true;
    
    printf("  Tea Robot: Done!\n");
    return NULL;
}




 
int main()
{
    srand(time(NULL));
    pthread_t t1;
    pthread_t t2;
    int err;

    err = pthread_create(&t1, NULL, me, NULL);
    assert(err == 0);
    err = pthread_create(&t2, NULL, teaRobot, NULL);
    assert(err == 0);

    err = pthread_join(t1, NULL); assert(err == 0);
    err = pthread_join(t2, NULL); assert(err == 0);
}