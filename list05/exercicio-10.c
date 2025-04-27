#include <stdio.h>
#include <stdlib.h>

void mergeArrays(int* array1, int size1, int* array2, int size2, int* array3);

int main() {
    printf(
        "This program receives two sorted arrays of integers and fills a third "
        "array with all elements from both, maintaining the sorted order.\n");

    int size1 = 0;
    printf("Write the size of the first array: \n");
    scanf("%d", &size1);

    int* array1 = NULL;
    array1 = malloc(sizeof(int) * size1);
    printf("Write the elements of the first array, in ascending order: \n");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &array1[i]);
    }

    int size2 = 0;
    printf("Write the size of the second array: \n");
    scanf("%d", &size2);

    int* array2 = NULL;
    array2 = malloc(sizeof(int) * size2);
    printf("Write the elements of the second array, in ascending order: \n");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &array2[i]);
    }

    int size3 = size1 + size2;

    int* array3 = NULL;
    array3 = malloc(sizeof(int) * size3);

    mergeArrays(array1, size1, array2, size2, array3);

    printf("The elements of the new sorted array are: \n");
    for (int i = 0; i < size3; i++) {
        printf("%d\n", array3[i]);
    }

    free(array1);
    free(array2);
    free(array3);

    return 0;
}

void mergeArrays(int* array1, int size1, int* array2, int size2, int* array3) {
    int i = 0;
    int j = 0;
    int k = 0;
    
    while (j < size1 && k < size2) {
        if (array1[j] < array2[k]) {
            array3[i] = array1[j];
            j++;
        } else {
            array3[i] = array2[k];
            k++;
        }
        i++;
    }

    while (j < size1) {
        array3[i] = array1[j];
        j++;
        i++;
    }

    while (k < size2) {
        array3[i] = array2[k];
        k++;
        i++;
    }
}