#include <stdio.h>
#include <stdlib.h>

int* removeDuplicates(int* vector1, int size1, int* size2);

int main() {
    printf(
        "This program receives two vectors of integers and creates a new "
        "vector without any duplicate elements.\n");

    int size1 = 0;
    printf("Write the size of the vector: \n");
    scanf("%d", &size1);

    int* vector1 = NULL;
    vector1 = malloc(sizeof(int) * size1);
    printf("Write the elements of the vector: \n");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &vector1[i]);
    }

    int size2 = 0;

    int* vector2 = removeDuplicates(vector1, size1, &size2);

    printf("The vector without any duplicates is: \n");
    for (int i = 0; i < size2; i++) {
        printf("%d\n", vector2[i]);
    }

    free(vector1);
    free(vector2);

    return 0;
}

int* removeDuplicates(int* vector1, int size1, int* size2) {
    int *temp = NULL;
    temp = malloc(sizeof(int) * size1);
    int count = 0;

    for (int i = 0; i < size1; i++) {
        int alreadyThere = 0;
        for (int j = 0; j < size1; j++) {
            if (vector1[i] == temp[j]) {
                alreadyThere = 1;
            }
        }
        if (!alreadyThere) {
            temp[count] = vector1[i];
            count++;
        }
    }

    *size2 = count;

    int* vector2 = NULL;
    vector2 = malloc(sizeof(int) * count);
    for (int i = 0; i < count; i++) {
        vector2[i] = temp[i];
    }
    free(temp);

    return vector2;
}