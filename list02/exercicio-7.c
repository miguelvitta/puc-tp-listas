#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool checkPrime(int number);

int main() {
    int number = 0;
    printf("Write a number to be checked for primality: ");
    scanf("%d", &number);
    bool isPrime = checkPrime(number);

    if (!isPrime) {
        printf("The number %d is not a Prime Number!\n", number);
    } else {
        printf("The number %d is a Prime Number!\n", number);
    }

    return 0;
}

bool checkPrime(int number) {
    if (number <= 1) {
        return false;
    }

    if (number == 2) {
        return true;
    }

    int rad = sqrt(number);
    int i = 2;
    for (; i <= rad && number % i != 0; i++);

    if (i > rad) {
        return true;
    }

    return false;
}

