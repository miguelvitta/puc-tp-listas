#include <stdio.h>

#define number 25

void printLine(char x);

int main(void) {
    printLine('*');
    printf("CMP 1048\n");
    printLine('@');
    printf("Técnicas de Programação\n");
    printLine('+');

    return 0;
}

void printLine(char x) {
    for(int i = 0; i < number; i++) {
        printf("%c", x);
    }
    printf("\n");
}


