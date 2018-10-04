#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Gimme N:\n");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        arr[i] = i;
        printf("%d ", i);
    }
    free(arr);
    return 0;
}
