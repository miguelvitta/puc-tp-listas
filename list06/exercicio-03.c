#include <stdio.h>
#include <stdlib.h>

float** createMatrix(int numRows, int numCols);
void readMatrix(float** matrix, int numRows, int numCols);
float** subtractMatrices(float** firstMatrix, float** secondMatrix, int numRowsFirst,
                    int numColsFirst, int numRowsSecond, int numColsSecond);
void printMatrix(float** matrix, int numRows, int numCols);
void freeMatrix(float** matrix, int numRows);

int main() {
    printf(
        "This program performs the following operations:\n"
        "  1. Dynamically creates float matrices.\n"
        "  2. Reads values into the matrices from user input.\n"
        "  3. Computes the subtraction of two matrices.\n"
        "  4. Prints the resulting matrix.\n"
        "  5. Frees the memory allocated for the matrices.\n");

    int numRowsFirst = 0;
    printf("Enter number of rows for the first matrix:\n");
    scanf("%d", &numRowsFirst);

    int numColsFirst = 0;
    printf("Enter number of columns  for the first matrix:\n");
    scanf("%d", &numColsFirst);

    float** firstMatrix = NULL;
    firstMatrix = createMatrix(numRowsFirst, numColsFirst);
    readMatrix(firstMatrix, numRowsFirst, numColsFirst);

    int numRowsSecond = 0;
    printf("Enter number of rows for the second matrix:\n");
    scanf("%d", &numRowsSecond);

    int numColsSecond = 0;
    printf("Enter number of columns  for the second matrix:\n");
    scanf("%d", &numColsSecond);

    float** secondMatrix = NULL;
    secondMatrix = createMatrix(numRowsSecond, numColsSecond);
    readMatrix(secondMatrix, numRowsSecond, numColsSecond);

    float** resultMatrix = NULL;
    resultMatrix = subtractMatrices(firstMatrix, secondMatrix, numRowsFirst,
                            numColsFirst, numRowsSecond, numColsSecond);
    if (resultMatrix == NULL) {
        fprintf(stderr,
                "Error - The number of columns and rows must be the same\n");
        freeMatrix(firstMatrix, numRowsFirst);
        freeMatrix(secondMatrix, numRowsSecond);
        return 1;
    }

    printf("Result of matrix subtraction:\n");
    printMatrix(resultMatrix, numRowsFirst, numColsFirst);

    freeMatrix(firstMatrix, numRowsFirst);
    freeMatrix(secondMatrix, numRowsSecond);
    freeMatrix(resultMatrix, numRowsFirst);
    return 0;
}

float** createMatrix(int numRows, int numCols) {
    float** matrix = NULL;
    matrix = malloc(sizeof(float*) * numRows);

    for (int i = 0; i < numRows; i++) {
        matrix[i] = malloc(sizeof(float) * numCols);
    }

    return matrix;
}

void readMatrix(float** matrix, int numRows, int numCols) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%f", &matrix[i][j]);
        }
    }
}

float** subtractMatrices(float** firstMatrix, float** secondMatrix, int numRowsFirst,
                    int numColsFirst, int numRowsSecond, int numColsSecond) {
    if (numRowsFirst != numRowsSecond || numColsFirst != numColsSecond) {
        return NULL;
    }

    float** matrix = NULL;
    matrix = malloc(sizeof(float*) * numRowsFirst);
    for (int i = 0; i < numRowsFirst; i++) {
        matrix[i] = malloc(sizeof(float) * numColsFirst);
    }

    for (int i = 0; i < numRowsFirst; i++) {
        for (int j = 0; j < numColsFirst; j++) {
            matrix[i][j] = firstMatrix[i][j] - secondMatrix[i][j];
        }
    }
    return matrix;
}

void printMatrix(float** matrix, int numRows, int numCols) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void freeMatrix(float** matrix, int numRows) {
    for (int i = 0; i < numRows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
