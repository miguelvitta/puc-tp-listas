#include <stdio.h>
#include <stdlib.h>

int** createMatrix(int numRows, int numCols);
void readMatrix(int** matrix, int numRows, int numCols);
int** extractMatrix(int** firstMatrix, int numRows, int numCols,
                    int startingRow, int startingCol, int subRows, int subCols);
void printMatrix(int** matrix, int numRows, int numCols);
void freeMatrix(int** matrix, int numRows);

int main() {
    printf(
        "This program performs the following operations:\n"
        "  1. Dynamically creates an integer matrix.\n"
        "  2. Reads values into the matrix from user input.\n"
        "  3. Receives a starting position (I2, J2) and size (L2, C2) to "
        "extract a submatrix.\n"
        "  4. Creates a new dynamic matrix containing the selected submatrix.\n"
        "  5. Prints the resulting submatrix if valid, or an error message "
        "otherwise.\n"
        "  6. Frees the memory allocated for both matrices.\n");

    int numRows = 0;
    printf("Enter number of rows for the first matrix:\n");
    scanf("%d", &numRows);

    int numCols = 0;
    printf("Enter number of columns  for the first matrix:\n");
    scanf("%d", &numCols);

    int** firstMatrix = NULL;
    firstMatrix = createMatrix(numRows, numCols);
    readMatrix(firstMatrix, numRows, numCols);

    int startingRow = 0;
    int startingCol = 0;
    printf("Enter the starting row (I2) and column (J2) for the submatrix:\n");
    scanf("%d %d", &startingRow, &startingCol);

    int subRows = 0;
    int subCols = 0;
    printf(
        "Enter the number of rows (L2) and columns (C2) for the submatrix:\n");
    scanf("%d %d", &subRows, &subCols);

    int** resultMatrix = NULL;
    resultMatrix = extractMatrix(firstMatrix, numRows, numCols, startingRow,
                                 startingCol, subRows, subCols);
    if (resultMatrix == NULL) {
        fprintf(
            stderr,
            "Error - The requested submatrix is out of bounds.\n");
        freeMatrix(firstMatrix, numRows);
        return 1;
    }

    printf("The matrix that was extracted was:\n");
    printMatrix(resultMatrix, subRows, subCols);

    freeMatrix(firstMatrix, numRows);
    freeMatrix(resultMatrix, subRows);
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

int** extractMatrix(int** firstMatrix, int numRows, int numCols,
                    int startingRow, int startingCol, int subRows,
                    int subCols) {
    if (startingRow < 0 || startingCol < 0 || startingRow + subRows > numRows ||
        startingCol + subCols > numCols) {
        return NULL;
    }

    int** matrix = NULL;
    matrix = malloc(sizeof(int*) * subRows);
    for (int i = 0; i < subRows; i++) {
        matrix[i] = malloc(sizeof(int) * subCols);
    }

    for (int i = 0; i < subRows; i++) {
        for (int j = 0; j < subCols; j++) {
            matrix[i][j] = firstMatrix[startingRow + i][startingCol + j];
        }
    }
    return matrix;
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
