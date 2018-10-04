#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *my_realloc(void *ptr, int original_size, int size) {
    if (size == 0) {
        free(ptr);
        return NULL;
    } else if (!ptr) {
        return malloc(size * sizeof(int));
    } else if (original_size >= size) {
        return ptr;
    } else {
        void *ptr_new = malloc(size * sizeof(int));
        if (ptr_new) {
            memcpy(ptr_new, ptr, original_size * sizeof(int));
            free(ptr);
        }
        return ptr_new;
    }
}

int main() {
    int n1;
    printf("Gimme N1:\n");
    scanf("%d", &n1);
    int *arr = malloc(n1 * sizeof(int));
    for (int i = 0; i < n1; i++) {
        arr[i] = i;
        printf("%d ", i);
    }

    int n2;
    printf("Gimme N2:\n");
    scanf("%d", &n2);

    arr = my_realloc(arr, n1, n2);
    for(int i = 0; i < n2; i++) {
		printf("%d ", arr[i]);
	}

    return 0;
}
