#include <stdio.h>
#include <stdlib.h>

int* findUnion(int* vector1, int size1, int* vector2, int size2, int* size3);

int main() {
    printf(
        "This program receives two vectors of integers and creates a new "
        "vector with the union of both vectors.\n");

    int size1 = 0;
    printf("Write the size of the first vector: \n");
    scanf("%d", &size1);

    int* vector1 = NULL;
    vector1 = malloc(sizeof(int) * size1);
    printf("Write the elements of the first vector: \n");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &vector1[i]);
    }

    int size2 = 0;
    printf("Write the size of the second vector: \n");
    scanf("%d", &size2);

    int* vector2 = NULL;
    vector2 = malloc(sizeof(int) * size2);
    printf("Write the elements of the second vector: \n");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &vector2[i]);
    }

    int size3 = 0;

    int* vector3 = findUnion(vector1, size1, vector2, size2, &size3);

    printf("The elements of the union are: \n");
    for (int i = 0; i < size3; i++) {
        printf("%d\n", vector3[i]);
    }

    free(vector1);
    free(vector2);
    free(vector3);

    return 0;
}

int* findUnion(int* vector1, int size1, int* vector2, int size2, int* size3) {
    int tempsize = size1 + size2;

    int *temp = NULL;
    temp = malloc(sizeof(int) * tempsize);
    int count = 0;

    for (; count < size1; count++) {
        temp[count] = vector1[count];
    }

    for (int i = 0; i < size2; i++) {
        int state = 0;
        int j = 0;
        for (; j < size1 && state == 0; j++) {
            if (vector2[i] == vector1[j]) {
                state = 1;
            }
        }
        if (j >= size1) {
            temp[count] = vector2[i];
            count++;
        }
    }
    *size3 = count;

    int* vector3 = NULL;
    vector3 = malloc(sizeof(int) * count);
    for (int i = 0; i < count; i++) {
        vector3[i] = temp[i];
    }
    free(temp);

    return vector3;
}