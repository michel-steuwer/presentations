#include "sem.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/* this semaphore is used to guard access to stdout */
sem_t my_sem;

void *fun1(void *args)
{
  int N = *(int *)args;

  while (N-- > 0) {
    usleep(100000);		/* sleep for 0.1 s */
    sem_wait(my_sem);	/* obtain exclusive access */
    printf("sub1: %d more tenths of a second to go\n", N);
    sem_signal(my_sem);/* release exclusive access */
  }
  return NULL;
}

void *fun2(void *args)
{
  int N = *(int *)args;

  while (N-- > 0) {
    usleep(50000);		/* sleep for 0.1 s */
    sem_wait(my_sem);	/* obtain exclusive access */
    printf("sub2: %d more twentieths of a second to go\n", N);
    sem_signal(my_sem);/* release exclusive access */
  }
  return NULL;
}

#define N1 10
#define N2 20

int main(int argc, char *argv[])
{
  pthread_t t1, t2;
  int n1 = N1, n2 = N2;

  my_sem = sem_create(1, 1);	/* create binary semaphore */
  printf("Creating thread 1: prints %d lines at 0.1 sec intervals\n", n1);
  if (pthread_create(&t1, NULL, fun1, (void *)&n1)) {
    fprintf(stderr, "Error creating thread 1\n");
    exit(1);
  }
  printf("Creating thread 2: prints %d lines at 0.05 sec intervals\n", n2);
  if (pthread_create(&t2, NULL, fun2, (void *)&n2)) {
    fprintf(stderr, "Error creating thread 2\n");
    exit(1);
  }
  pthread_join(t1, NULL);		/* wait for thread 1 to finish */
  pthread_join(t2, NULL);		/* wait for thread 2 to finish */
  sem_destroy(my_sem);
}
