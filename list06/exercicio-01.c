#include <stdio.h>
#include <stdlib.h>

int** createMatrix(int numRows, int numCols);
void readMatrix(int** matrix, int numRows, int numCols);
void printMatrix(int** matrix, int numRows, int numCols);
void freeMatrix(int** matrix, int numRows);

int main() {
    printf("This program performs the following operations:\n"
           "  1. Dynamically creates an integer matrix.\n"
           "  2. Reads values into the matrix from user input.\n"
           "  3. Prints the values stored in the matrix.\n"
           "  4. Frees the memory allocated for the matrix when it's no longer needed.\n\n");


    return 0;
}

int** createMatrix(int numRows, int numCols) {

}

void readMatrix(int** matrix, int numRows, int numCols) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
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
