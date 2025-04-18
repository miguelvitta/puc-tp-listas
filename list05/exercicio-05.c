#include <stdio.h>
#include <stdlib.h>

#define VECTOR_SIZE 10

int findNumber(unsigned int* vector, int n, unsigned int number);

int main() {
    unsigned int* vector = NULL;
    vector = malloc(sizeof(unsigned int) * VECTOR_SIZE);

    printf(
        "This program receives a vector of positive numbers and a positive "
        "number and then finds the number in the vector. Or -1 in case of not "
        "finding the number.\n");

    printf("Enter the values of the vector:\n");
    for (int i = 0; i < VECTOR_SIZE; i++) {
        scanf("%d", &vector[i]);
    }

    unsigned int number = 0;
    printf("Enter the number to be found:\n");
    scanf("%u", &number);

    int index = findNumber(vector, VECTOR_SIZE, number);

    if (index == -1) {
        printf("The number was not found!\n");
    }
    else {
        printf("The number is at index: %d\n", index);
    }

    free(vector);

    return 0;
}

int findNumber(unsigned int* vector, int n, unsigned int number) {
    int index = 0;
    int valid = 0;
    for (int i = 0; i < n && valid == 0; i++) {
        if (vector[i] == number) {
            index = i;
            valid = 1;
        }
    }
    if (valid == 0) {
        index = -1;
    }
    return index;
}