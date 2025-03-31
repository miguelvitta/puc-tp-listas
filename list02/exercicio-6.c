#include <stdio.h>

int calculateFactorial(int number, int accumulator);

int main() {
    int number = 0;
    printf("Write a number to calculate it's factorial: ");
    scanf("%d", &number);

    int accumulator = 1;
    int factorial = calculateFactorial(number, accumulator);

    printf("The factorial of %d is: %d\n", number, factorial);

    return 0;
}

int calculateFactorial(int number, int accumulator) {
    if (number == 0) {
        return accumulator;
    } else {
        return calculateFactorial(number - 1, number * accumulator);
    }
}

