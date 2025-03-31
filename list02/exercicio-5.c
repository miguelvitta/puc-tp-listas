#include <math.h>
#include <stdio.h>

double calculateLogarithm(double number, double base);

int main() {
    double number = 0.0;
    double base = 0.0;

    printf("Write the number: ");
    scanf("%lf", &number);
    printf("Write the base: ");
    scanf("%lf", &base);

    if (number <= 0 || base <= 1) {
        printf("Invalid numbers\n");
    } else {
        double result = calculateLogarithm(number, base);
        printf("The log with base: %.6lf and number: %.6lf is: %.6lf\n", base,
               number, result);
    }

    return 0;
}

double calculateLogarithm(double number, double base) {
    return log(number) / log(base);
}

