#include <stdio.h>

#define SIZE 3

double getAverage(const double* x);

int main() {
    double grade[SIZE] = {0.0};
    printf("Insert the 3 grade values: ");
    for (int i = 0; i < SIZE; i++) {
        scanf("%lf", &grade[i]);
    }

    double average = getAverage(grade);

    printf("The average value of the grades is: %.2lf\n", average);

    return 0;
}

double getAverage(const double* x) {
    double average = 0.0;
    for (int i = 0; i < SIZE; i++) {
        average += x[i];
    }
    return average / SIZE;
}

