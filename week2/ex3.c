#include <stdio.h>

int main() {
    int n;
    char str[100];
    printf("Gimme n:\n");
    scanf("%s", str);
    sscanf(str, "%d", &n);
    printf("%d\n", n);

    int i; // height
    int space; // space counter
    int star; // stars counter

    // i = 0 : 1 star
    // i = 1 : 3 stars
    // i = 2 : 5 stars
    // int height = n;
    // int width = 2*n - 1;
    // char *matrix
    // matrix = (int *)malloc(height * width * sizeof(char));

    for (i = 0; i < n; i++) {
        for (space = 0; space < (n - i - 1); space++) {
            printf(" ");
        }
        for (star = 0; star < i * 2 + 1; star++) {
            printf("*");
        }
        for (space = 0; space < (n - i - 1); space++) {
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}
