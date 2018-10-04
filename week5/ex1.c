#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

char *p;
int N;

void *threadFunct(void *arg) {
    int *num = (int *)arg;
    printf("Obi-Wan Kenobi: Hello there!\n");
    printf("Grievous: General Kenobi...\n");
    printf("%i times\n", *num);
    return 0;
}

int main(int argc, char** argv) {
    int n = strtol(argv[1], &p, 10);
    printf("n = %d\n", n);

    pthread_t thread_id;
    for (int i = 0; i < n; i++) {
        printf("Thread %d created\n", i);
        pthread_create(&thread_id, NULL, threadFunct, (void*) &i);
        pthread_join(thread_id, NULL);
        printf("Thread %d terminated\n", i);
    }

    return 0;
}
