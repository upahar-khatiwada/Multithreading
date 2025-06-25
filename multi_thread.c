#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* t1(void* arg1) {
    int *id = (int *)arg1;
    printf("First thread running with id %d\n", *id);
    sleep(2);
    printf("First thread exited\n");

    return NULL;
}

void *t2(void* arg2) {
    int *id = (int *)arg2;
    printf("Second thread running with id %d\n", *id);
    sleep(1);
    printf("Second thread exited\n");

    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    int *arg1 = malloc(sizeof(int));
    int *arg2 = malloc(sizeof(int));
    *arg1 = 1;
    *arg2 = 2;

    pthread_create(&thread1, NULL, t1, (void *)arg1);
    pthread_create(&thread2, NULL, t2, (void *)arg2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    free(arg1);
    free(arg2);

    printf("Both threads finished!\n");

    return 0;
}
