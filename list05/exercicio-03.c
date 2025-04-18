#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define VECTOR_SIZE 10

int findBigger(int* vector, int n);

int main() {
    int* vector = NULL;
    vector = malloc(sizeof(int) * VECTOR_SIZE);

    printf("This program receives a vector and prints the index of the first occurrence of the biggest element in the vector.\n");

    printf("Enter the values of the vector:\n");
    for (int i = 0; i < VECTOR_SIZE; i++) {
        scanf("%d", &vector[i]);
    }

    int index = findBigger(vector, VECTOR_SIZE);

    printf("The bigger value is at index: %d\n", index);

    free(vector);

    return 0;
}

int findBigger(int* vector, int n) {
    int index = 0;
    int value = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (vector[i] > value) {
            index = i;
            value = vector[i];
        }
    }
    return index;
}