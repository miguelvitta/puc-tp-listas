#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define VECTOR_SIZE 10

int findLowest(int* vector, int n);

int main() {
    int* vector = NULL;
    vector = malloc(sizeof(int) * VECTOR_SIZE);

    printf("This program receives a vector and prints the index of the first occurrence of the smallest element in the vector.\n");

    printf("Enter the values of the vector:\n");
    for (int i = 0; i < VECTOR_SIZE; i++) {
        scanf("%d", &vector[i]);
    }

    int index = findLowest(vector, VECTOR_SIZE);

    printf("The lowest value is at index: %d\n", index);

    free(vector);

    return 0;
}

int findLowest(int* vector, int n) {
    int index = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (vector[i] < index) {
            index = i;
        }
    }
    return index;
}