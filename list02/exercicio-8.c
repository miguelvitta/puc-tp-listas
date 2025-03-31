#include <stdio.h>

int getFibonacci(int number, int fib1, int fib2);

int main() {
    int number = 0;
    printf("Write the nth term (1 -....) of the Fibonacci Sequence to be determined: ");
    scanf("%d", &number);

    int fib1 = 0;
    int fib2 = 1;
    int fibNumber = getFibonacci(number, fib1, fib2);

    printf("The %d term of the Fibonacci Sequence is: %d\n", number, fibNumber);

    return 0;
}

int getFibonacci(int number, int fib1, int fib2) {
    if (number == 1) {
        return fib1;
    }
    if (number == 2) {
        return fib2;
    }
    return getFibonacci(number - 1, fib2, fib1 + fib2);
}

