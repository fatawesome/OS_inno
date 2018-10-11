#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    for (int i = 0; i < 10; i++) {
        int *arr = malloc(10 * 262144 * sizeof(int));
        memset(arr, 0, 10 * 262144 * sizeof(int));
        sleep(1);
    }
    return 0;
}
