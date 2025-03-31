#include <stdio.h>

int checkRegular(int number);

int main() {
    int number = 0;
    printf("Write the number to see if it's a regular number: ");
    scanf("%d", &number);

    int result = checkRegular(number);

    if (result == 1) {
        printf("The number %d is a Regular Number\n", number);
    } else {
        printf("The number %d is not a Regular Number\n", number);
    }

    return 0;
}

int checkRegular(int number) {
    if (number <= 0) {
        return 0;
    }

    while (number % 5 == 0) {
        number /= 5;
    }
    while (number % 3 == 0) {
        number /= 3;
    }
    while (number % 2 == 0) {
        number /= 2;
    }

    return (number == 1) ? 1 : 0;
}

