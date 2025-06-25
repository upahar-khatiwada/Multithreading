#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

void* t1(void* arg1) {
    for (int i = 0; i < 5; i++) {
        printf("T1: %d\n", i);
        sleep(1);
    }
    return NULL;
}

void* t2(void* arg2) {
    for (int i = 0; i < 5; i++) {
        printf("T2: %d\n", i);
        sleep(1);
    }
    return NULL;
}


int main() {
    struct timeval start, end;
    gettimeofday(&start, NULL);
    pthread_t thread1, thread2;

    int *arg1 = malloc(sizeof(int));
    int *arg2 = malloc(sizeof(int));
    *arg1 = 1;
    *arg2 = 2;

    pthread_create(&thread1, NULL, t1, (void *)arg1);
    pthread_create(&thread2, NULL, t2, (void *)arg2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    gettimeofday(&end, NULL);
    double elapsed = (end.tv_sec - start.tv_sec) + 
                 (end.tv_usec - start.tv_usec) / 1e6;

    printf("Elapsed: %.2f seconds\n", elapsed);

    free(arg1);
    free(arg2);

    printf("Both threads finished!\n");

    return 0;
}
