#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    int pid = fork();
    int n = 10;
    if (pid > 0) {
        printf("Hello from parent [%d - %d]\n", pid, n);
    } else if (pid == 0) {
        printf("Hello from child [%d - %d]\n", pid, n);
    } else {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
