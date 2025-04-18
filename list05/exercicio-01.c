#include <stdio.h>
#include <stdlib.h>

int* createVector(int size);
void printVector(int* vector, int size);
void readVector(int* vector, int size);
int* resizeVector(int* vector, int originalSize, int newSize);
void freeVector(int* vector);

int main() {
    printf("Welcome to the dynamic vector manipulation program!\n"
           "This program performs the following operations:\n"
           "  1. Dynamically creates an integer vector with all elements initialized to 0.\n"
           "  2. Reads values into the vector from user input.\n"
           "  3. Prints the values stored in the vector.\n"
           "  4. Resizes the vector to a new size, preserving existing elements where possible;\n"
           "     if the new size is smaller, excess elements are discarded.\n"
           "  5. Frees the memory allocated for the vector when it's no longer needed.\n\n");

    int size = 0;
    printf("Enter the initial size of the vector: ");
    scanf("%d", &size);

    int* vector = NULL;
    vector = createVector(size);
    if (vector == NULL) {
        return 1;
    }

    printVector(vector, size);
    readVector(vector, size);
    printVector(vector, size);

    int newSize = 0;
    printf("Enter the new size of the vector: ");
    scanf("%d", &newSize);

    int* newVector = NULL;
    newVector = resizeVector(vector, size, newSize);
    if (newVector == NULL) {
        freeVector(vector);
        return 1;
    }

    size = newSize;
    printVector(newVector, size);

    freeVector(newVector);

    return 0;
}

int* createVector(int size) {
    int* vector = malloc(sizeof(int) * size);
    if (vector == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        vector[i] = 0;
    }

    return vector;
}

void printVector(int* vector, int size) {
    printf("Current vector content:\n");
    for (int i = 0; i < size; i++) {
        printf("vector[%d] = %d\n", i, vector[i]);
    }      
}

void readVector(int* vector, int size) {
    printf("Enter new values for the vector:\n");
    for (int i = 0; i < size; i++) {
        printf("vector[%d] = ", i);
        scanf("%d", &vector[i]);
    }
}

int* resizeVector(int* vector, int originalSize, int newSize) {
    int* newVector = malloc(sizeof(int) * newSize);
    if (newVector == NULL) {
        printf("Memory allocation failed during resizing.\n");
        return NULL;
    }

    int minSize = (originalSize < newSize) ? originalSize : newSize;

    for (int i = 0; i < minSize; i++) {
        newVector[i] = vector[i];
    }

    for (int i = minSize; i < newSize; i++) {
        newVector[i] = 0;
    }

    freeVector(vector);
    return newVector;
}

void freeVector(int* vector) {
    free(vector);
}
