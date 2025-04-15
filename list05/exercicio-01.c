#include <stdio.h>
#include <stdlib.h>

int* createVector(int size);
void printVector(int* vector, int size);
void readVector(int* vector, int size);
int* resizeVector(int* vector, int newSize);
void freeVector(int* vector);

int main() {
    printf("Bem-vindo ao programa de manipulacao de vetores dinâmicos!\n"
           "Este programa executa as seguintes operacoes:\n"
           "  1. Cria dinamicamente um vetor de inteiros com todas as posicoes inicializadas em 0.\n"
           "  2. Realiza a leitura dos valores do vetor a partir da entrada do usuario.\n"
           "  3. Imprime os valores armazenados no vetor.\n"
           "  4. Permite o redimensionamento do vetor para um novo tamanho, transferindo os elementos existentes; "
           "caso o novo tamanho seja menor, os elementos excedentes serao descartados.\n"
           "  5. Libera a memoria alocada para o vetor quando ela nao for mais necessaria.\n\n");

    int size = 0;
    printf("Write the size of the vector: ");
    scanf("%d", &size);

    int *vector = NULL;
    vector = createVector(size);

    printVector(vector, size);
    readVector(vector, size);
    printVector(vector, size);

    int newSize = 0;
    printf("Write the new size of the vector: ");
    scanf("%d", &newSize);

    int* newVector = NULL;
    newVector = resizeVector(vector, newSize);
    printVector(newVector, newSize);

    freeVector(newVector);

    return 0;
}

int* createVector(int size) {
    int* vector = NULL;
    vector = malloc(sizeof(vector) * size);
    for (int i = 0; i < size; i++) {
        vector[i] = 0;
    }

    return vector;
}

void printVector(int* vector, int size) {
    for (int i = 0; i < size; i++) {
        printf("vector [%d] = %d\n", i, vector[i]);
    }      
}

void readVector(int* vector, int size) {
    printf("Write new values to the vector:");
    for (int i = 0; i < size; i++) {
        scanf("%d", &vector[i]);
    }
}

int* resizeVector(int* vector, int newSize) {
    int* newVector = NULL;
    newVector = malloc(sizeof(newVector) * newSize);

    for (int i = 0; i < newSize; i++) {
        newVector[i] = vector[i];
    }

    freeVector(vector);
    return newVector;
}

void freeVector(int* vector) {
   free(vector);
}
