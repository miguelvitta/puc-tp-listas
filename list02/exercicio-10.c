#include <stdio.h>

long long int calculateCombination(long long int n, long long int p);
long long int factorial(long long int number, long long int acc);

int main() {
    long long int n = 0;
    long long int p = 0;
    printf("To make the calculation of the combination of n and p possible\n");
    printf("Write the number n: ");
    scanf("%lld", &n);
    printf("Write the number p: ");
    scanf("%lld", &p);

    long long int combination = calculateCombination(n, p);

    printf("The combination of %lld elements p to p is: %lld\n", n,
           combination);

    return 0;
}

long long int calculateCombination(long long int n, long long int p) {
    long long int acc = 1;
    return factorial(n, acc) / (factorial(p, acc) * factorial(n - p, acc));
}

long long int factorial(long long int number, long long int acc) {
    if (number == 0) {
        return acc;
    } else {
        return factorial(number - 1, number * acc);
    }
}

