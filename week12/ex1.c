#include <stdio.h>
#include <unistd.h>

int main() {
    int in = open("/dev/random");
    char s[21];
    read(in, s, 20);
    s[20] = 0;
    printf("%s", s);
    return 0;
}
