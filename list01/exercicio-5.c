#include <stdio.h>

void drawRectangle(int lines, int columns, char symbol1, char symbol2);

int main(void) {
    int lines, columns;
    char symbol1, symbol2;
    printf("Write the number of lines: ");
    scanf(" %d", &lines);
    printf("Write the number of columns: ");
    scanf(" %d", &columns);
    printf("Write the symbol to be printed as border: ");
    scanf(" %c", &symbol1);
    printf("Write the symbol to be printed in the interior: ");
    scanf(" %c", &symbol2);
    
    drawRectangle(lines, columns, symbol1, symbol2);

    return 0;
}

void drawRectangle(int lines, int columns, char symbol1, char symbol2) {
    int limitColumns = columns - 1;
    int limitLines = lines - 1;
    for (int i = 0; i < lines; i ++) {
        for (int j = 0; j < columns; j++) {
            if (i == 0 || i == limitLines || j == 0 || j == limitColumns) {
                printf("%c", symbol1);
            }
            else {
                printf("%c", symbol2);
            }
        }
        printf("\n");
    }
}




