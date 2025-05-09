#include <stdio.h>

int main() {
    int s = 0, n = 0;
    scanf("%d", &n);
    while (n >= 0) {
        s = s + n;
        if (s >= 100) {
            s = 0;
        }
        scanf("%d", &n);
    }
    printf("%d\n", s);

    return 0;
}