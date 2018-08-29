#include <stdio.h>
#include <string.h>

int main() {
    char str[100], temp;
    printf("Gimme str\n");
    scanf("%[^\n]", str);

    int i = 0;
    int j = strlen(str) - 1;
    while(i < j){
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }

    printf("%s\n",str);

    return(0);
}
