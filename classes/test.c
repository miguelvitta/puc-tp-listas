#include <stdio.h>

int main() {
    double a = 0.1;
    double b = 0;

    for (int i = 0; i < 1000000; i++) {
        b = b + a;
    }

    printf("%lf\n", b);

    return 0;
}