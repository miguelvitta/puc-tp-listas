#include <stdio.h>
#include <stdlib.h>

#define VECTOR_SIZE 10

double calculateAverage(int* vector, int n);

int main() {
    int* vector = NULL;
    vector = malloc(sizeof(int) * VECTOR_SIZE);

    printf("This program receives a vector and calculates the average.\n");

    printf("Enter the values of the vector:\n");
    for (int i = 0; i < VECTOR_SIZE; i++) {
        scanf("%d", &vector[i]);
    }

    double average = calculateAverage(vector, VECTOR_SIZE);

    printf("The average is: %lf\n", average);

    free(vector);

    return 0;
}

double calculateAverage(int* vector, int n) {
    double average = 0.0;
    for (int i = 0; i < n; i++) {
        average += vector[i];
    }
    average /= n;
    return average;
}