#include <stdio.h>

void drawRectangle(int lines, int columns, char symbol);

int main(void) {
    int lines, columns;
    char symbol;
    printf("Write the number of lines: ");
    scanf(" %d", &lines);
    printf("Write the number of columns: ");
    scanf(" %d", &columns);
    printf("Write the symbol to be printed: ");
    scanf(" %c", &symbol);
    
    drawRectangle(lines, columns, symbol);

    return 0;
}

void drawRectangle(int lines, int columns, char symbol) {
    for (int i = 0; i < lines; i ++) {
        for (int j = 0; j < columns; j++) {
            printf("%c", symbol);
        }
        printf("\n");
    }
}


