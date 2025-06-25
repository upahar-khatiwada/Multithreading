#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutex_t mutex;

void *func(void *arg) {
    pthread_mutex_lock(&mutex);

    pthread_t thisThread = pthread_self();
    printf("Current thread ID: %lu\n", (unsigned long)thisThread);
    sleep(2);

    pthread_mutex_unlock(&mutex);
}

int main() {
    pthread_t thread1;
    pthread_t thread2;

    pthread_create(&thread1, NULL, &func, NULL);
    pthread_create(&thread2, NULL, &func, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}