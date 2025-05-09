#include <stdio.h>
#include <stdlib.h>

int** createMatrix(int numRows, int numCols);
void readMatrix(int** matrix, int numRows, int numCols);
int** resizeMatrix(int** firstMatrix, int numRows, int numCols, int newRows,
                   int newCols);
void printMatrix(int** matrix, int numRows, int numCols);
void freeMatrix(int** matrix, int numRows);

int main() {
    printf(
        "This program performs the following operations:\n"
        "  1. Dynamically creates an integer matrix based on user-defined "
        "size.\n"
        "  2. Reads values into the matrix from user input.\n"
        "  3. Receives new dimensions (L, C) to resize the original matrix.\n"
        "  4. Allocates a new matrix with the specified dimensions and copies\n"
        "     the appropriate elements from the original matrix.\n"
        "  5. Frees the memory allocated for the original matrix.\n"
        "  6. Returns a pointer to the newly resized matrix.\n");

    int numRows = 0;
    printf("Enter number of rows for the first matrix:\n");
    scanf("%d", &numRows);

    int numCols = 0;
    printf("Enter number of columns  for the first matrix:\n");
    scanf("%d", &numCols);

    int** firstMatrix = NULL;
    firstMatrix = createMatrix(numRows, numCols);
    readMatrix(firstMatrix, numRows, numCols);

    int newRows = 0;
    int newCols = 0;
    printf("Enter the new number of rows and columns to resize the matrix:\n");
    scanf("%d %d", &newRows, &newCols);

    int** resultMatrix = NULL;
    resultMatrix =
        resizeMatrix(firstMatrix, numRows, numCols, newRows, newCols);

    printf("The new matrix has this components:\n");
    printMatrix(resultMatrix, newRows, newCols);

    freeMatrix(resultMatrix, newRows);
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

int** resizeMatrix(int** firstMatrix, int numRows, int numCols, int newRows,
                   int newCols) {
    int** matrix = NULL;
    matrix = malloc(sizeof(int*) * newRows);
    for (int i = 0; i < newRows; i++) {
        matrix[i] = malloc(sizeof(int) * newCols);
    }

    for (int i = 0; i < newRows; i++) {
        for (int j = 0; j < newCols; j++) {
            matrix[i][j] = 0;
        }
    }

    int limitRows = (numRows > newRows) ? newRows : numRows;
    int limitCols = (numCols > newCols) ? newCols : numCols;

    for (int i = 0; i < limitRows; i++) {
        for (int j = 0; j < limitCols; j++) {
            matrix[i][j] = firstMatrix[i][j];
        }
    }

    freeMatrix(firstMatrix, numRows);
    return matrix;
}

void printMatrix(int** matrix, int numRows, int numCols) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            printf("%d\t", matrix[i][j]);
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
