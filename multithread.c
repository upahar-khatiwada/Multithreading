#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* t1(void* arg1) {
    printf("First thread running\n");
    sleep(2);
    printf("First thread exited\n");
}

void *t2(void* arg2) {
    printf("Second thread running\n");
    sleep(1);
    printf("Second thread exited\n");
}

int main() {
    pthread_t thread1;
    pthread_t thread2;

    pthread_create(&thread1, NULL, t1, NULL);
    pthread_create(&thread2, NULL, t2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Both threads finished!\n");

    return 0;
}

