#include <stdio.h>
#include <stdlib.h>

int* createVector(int size);
void freeVector(int* vector);
void readVector(int* vector, int size);
void printVector(int* vector, int size);
int* resizeVector(int* vector, int originalSize, int newSize);

int main() {
    printf("Bem-vindo ao programa de manipulacao de vetores dinâmicos!\n"
           "Este programa executa as seguintes operacoes:\n"
           "  1. Cria dinamicamente um vetor de inteiros com todas as posicoes inicializadas em 0.\n"
           "  2. Realiza a leitura dos valores do vetor a partir da entrada do usuario.\n"
           "  3. Imprime os valores armazenados no vetor.\n"
           "  4. Permite o redimensionamento do vetor para um novo tamanho, transferindo os elementos existentes; "
           "caso o novo tamanho seja menor, os elementos excedentes serao descartados.\n"
           "  5. Libera a memoria alocada para o vetor quando ela nao for mais necessaria.\n\n");

    int size, newSize;
    int *vector = NULL;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &size);
    vector = createVector(size);

    freeVector(vector);

    return 0;
}

int* createVector(int size) {
   

    return NULL;
}

void freeVector(int* vector) {
   
}

void readVector(int* vector, int size) {
  
}

void printVector(int* vector, int size) {
    
}

int* resizeVector(int* vector, int originalSize, int newSize) {
    
    return NULL;
}
