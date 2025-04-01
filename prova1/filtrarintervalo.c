#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* filtrarIntervalo(int numbers[], int size, int parameterLow, int parameterHigh, int* qtde);

int main() {
    int size = 0;
    printf("Write the size of the array: ");
    scanf("%d", &size);

    int* numbers = NULL;
    numbers = malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++) {
        scanf("%d", &numbers[i]);
    }

    int parameterLow = 0;
    int parameterHigh = 0;
    printf("Write the lower parameter: ");
    scanf("%d", &parameterLow);
    printf("Write the higher parameter: ");
    scanf("%d", &parameterHigh);
    printf("l: %d\nh: %d\n", parameterLow, parameterHigh);

    int qtde = 0;

    int* newNumbers = filtrarIntervalo(numbers, size, parameterLow, parameterHigh, &qtde);

    for (int i = 0; i < qtde; i++) {
        printf("%d\n", newNumbers[i]);
    }


    free(numbers);
    free(newNumbers);
    return 0;
}


int* filtrarIntervalo(int numbers[], int size, int parameterLow, int parameterHigh, int* qtde) {
    int newSize = 0;
    for (int i = 0; i < size; i++) {
        if (numbers[i] <= parameterHigh && numbers[i] >= parameterLow) {
            newSize++;
        }
    }
    int* newNumbers = NULL;
    newNumbers = malloc(sizeof(int) * newSize);
    for (int i = 0; i < newSize; i++) {
        newNumbers[i] = 0;
    }
    *qtde = newSize;

    for (int i = 0, j = 0; i < newSize+1; i++) {
        if (numbers[i] <= parameterHigh && numbers[i] >= parameterLow) {
            newNumbers[j] = numbers[i];
            j++;
        }
    }

    return newNumbers;
}