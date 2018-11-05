/*
  * sem.c - implementation of simple semaphore abstract data type using PThreads
  */

#include "sem.h"
#include <pthread.h>
#include <stdlib.h>

/* the actual data structure for a semaphore */
typedef struct sem {
    pthread_mutex_t mut;
    pthread_cond_t cv;
    unsigned int value;
    unsigned int maxval;
} Semaphore;

/* create a semaphore, assigning its initial value, noting its maximum value
  * returns the semaphore, or NULL if failure */
sem_t sem_create(unsigned int initial, unsigned int maximum) {
    Semaphore *p;

    if ((p = (Semaphore *)malloc(sizeof(Semaphore))) != NULL) {
        pthread_mutex_init(&(p->mut), NULL);
        pthread_cond_init(&(p->cv), NULL);
        p->value = (initial < SEM_MAX_VALUE) ? initial: SEM_MAX_VALUE;
        p->maxval = (maximum < SEM_MAX_VALUE) ? maximum: SEM_MAX_VALUE;
    }
    return (sem_t)p;
}

/* destroy the semaphore; return 1 if successful, 0 otherwise */
int sem_destroy (sem_t s) {
    Semaphore *p = (Semaphore *)s;

    pthread_mutex_lock(&(p->mut));
    pthread_cond_destroy(&(p->cv));
    pthread_mutex_unlock(&(p->mut));
    pthread_mutex_destroy(&(p->mut));
    free(p);
    return 1;
}

/* signal the semaphore; returns 1 if successful, 0 otherwise */
int sem_signal(sem_t s) {
    Semaphore *p = (Semaphore *)s;

    pthread_mutex_lock(&(p->mut));
    p->value++;
    pthread_cond_signal(&(p->cv));
    pthread_mutex_unlock(&(p->mut));
    return 1;
}

/* wait for the semaphore; returns 1 if successful, 0 otherwise */
int sem_wait (sem_t s) {
    Semaphore *p = (Semaphore *)s;

    pthread_mutex_lock(&(p->mut));
    while (p->value <= 0)
        pthread_cond_wait(&(p->cv), &(p->mut));
    p->value--;
    pthread_mutex_unlock(&(p->mut));
    return 1;
}
