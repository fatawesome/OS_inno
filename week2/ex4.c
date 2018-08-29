#include <stdio.h>

void swap(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main() {
    int a, b;

    printf("Gimme numbers\n");
    scanf("%d%d", &a, &b);
    printf("You gave me %d and %d\n", a, b);
    printf("Swapping...\n");

    swap(&a, &b);
    printf("Take it: %d %d\n", a, b);

    return 0;
}
