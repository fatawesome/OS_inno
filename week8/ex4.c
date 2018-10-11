#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    struct rusage use;
    for (int i = 0; i < 10; i++) {
        int *arr = malloc(10 * 262144 * sizeof(int));
        memset(arr, 0, 10 * 262144 * sizeof(int));
        getrusage(RUSAGE_SELF, &use);
        printf("%lu\n",use.ru_maxrss);
        sleep(1);
    }
    return 0;
}
