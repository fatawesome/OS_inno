#include <limits.h>
#include <float.h>
#include <stdio.h>

int main() {
    int a;
    float b;
    double c;
    a = INT_MAX;
    b = FLT_MAX;
    c = DBL_MAX;

    printf("%d\n%.10e\n%.10e\n", a, b, c);
}
