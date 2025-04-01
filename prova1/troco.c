#include <stdio.h>
#include <stdlib.h>

#define SIZE_INTS 7

int* troco(double real);

int main() {
    double real = 0.0;
    scanf("%lf", &real);

    int* qtde = troco(real);

    char* text[1001] = {"Moeda de R$ 2,00: ", "Moeda de R$ 1,00: ", "Moeda de R$ 0,50: ", "Moeda de R$ 0,25: ", "Moeda de R$ 0,10: ", "Moeda de R$ 0,05: ", "Moeda de R$ 0,01: "};
    for (int i = 0; i < SIZE_INTS; i++) {
        if (qtde[i] > 0) {
            printf("%s%d\n", text[i], qtde[i]);
        }
    }

    free(qtde);
    return 0;
}

int* troco(double real) {
    int num1 = real * 100;
    int* numbers = NULL;
    numbers = malloc(sizeof(int) * SIZE_INTS);

    for (int i = 0; i < SIZE_INTS; i++) {
        numbers[i] = 0;
    }

    int moedas[SIZE_INTS] = {200, 100, 50, 25, 10, 5, 1};

    for (int i = 0; i < SIZE_INTS; i++) {
        numbers[i] = num1 / moedas[i];
        num1 = num1 % moedas[i];
    }

    return numbers;
}