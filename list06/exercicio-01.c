#include <stdio.h>
#include <stdlib.h>

int** createMatrix(int numRows, int numCols);
void readMatrix(int** matrix, int numRows, int numCols);
void printMatrix(int** matrix, int numRows, int numCols);
void freeMatrix(int** matrix, int numRows);

int main() {
    printf(
        "This program performs the following operations:\n"
        "  1. Dynamically creates an integer matrix.\n"
        "  2. Reads values into the matrix from user input.\n"
        "  3. Prints the values stored in the matrix.\n"
        "  4. Frees the memory allocated for the matrix when it's no longer "
        "needed.\n");

    int numRows = 0;
    printf("Write the number of rows:\n");
    scanf("%d", &numRows);

    int numCols = 0;
    printf("Write the number of columns:\n");
    scanf("%d", &numCols);

    int** matrix = NULL;
    matrix = createMatrix(numRows, numCols);

    readMatrix(matrix, numRows, numCols);

    printMatrix(matrix, numRows, numCols);

    freeMatrix(matrix, numRows);
    return 0;
}

int** createMatrix(int numRows, int numCols) {
    int** matrix = NULL;
    matrix = malloc(sizeof(int*) * numRows);

    for (int i = 0; i < numRows; i++) {
        matrix[i] = malloc(sizeof(int) * numCols);
    }

    return matrix;
}

void readMatrix(int** matrix, int numRows, int numCols) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int** matrix, int numRows, int numCols) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void freeMatrix(int** matrix, int numRows) {
    for (int i = 0; i < numRows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
