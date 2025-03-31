#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZESTRING 1001
#define SIZEINT 10

void getString(char* str);
size_t removeTrailing(size_t n, char* str);
int getInt();
void printBox(char* str, int number, int border);
void printLine(int number, int border);
void printMiddle(char* str, int number, int border);

int main() {
    char* string = NULL;
    string = (char*)malloc(sizeof(char) * SIZESTRING);
    if (string == NULL) {
        fprintf(stderr, "Memory allocation has failed\n");
        return 1;
    }

    getString(string);

    int number = getInt();
    printf("Write the symbol to be used as border: ");
    int border = getchar();

    printBox(string, number, border);

    free(string);
    return 0;
}

void getString(char* str) {
    printf("Enter the string: ");
    if (fgets(str, SIZESTRING, stdin) != NULL) {
        size_t len = strlen(str);
        len = removeTrailing(len, str);

        if (len == 0) {
            fprintf(stderr, "\nInput cannont be empty. Try again: ");
            getString(str);
        }
    } else {
        fprintf(stderr, "\nError reading the string.\n");
    }
}

size_t removeTrailing(size_t n, char* str) {
    if (n > 0 && str[n - 1] == '\n') {
        str[n - 1] = '\0';
        n--;
    }
    return n;
}

int getInt() {
    int number = 0;
    char buffer[SIZEINT];
    printf("Enter the Number of border symbols to be used: ");
    if (fgets(buffer, SIZEINT, stdin) != NULL) {
        size_t len = strlen(buffer);
        len = removeTrailing(len, buffer);

        for (size_t i = 0; i < len; i++) {
            if (!isdigit(buffer[i])) {
                fprintf(stderr, "\nThis is not a valid number.\n");
                return 0;
            }
            number = number * 10 + (buffer[i] - '0');
            if (number < 0) {
                fprintf(stderr, "\nNumber is too large.\n");
                return 0;
            }
        }
    }
    return number;
}

void printBox(char* str, int number, int border) {
    printLine(number, border);
    printMiddle(str, number, border);
    printLine(number, border);
}

void printLine(int n, int border) {
    for (int i = 0; i < n; i++) {
        printf("%c", border);
    }
    printf("\n");
}

void printMiddle(char* str, int number, int border) {
    size_t len = strlen(str);
    size_t totalSpaces = number - len - 2;
    size_t leftSpaces = totalSpaces / 2;
    size_t rightSpaces = totalSpaces - leftSpaces;
    
    if (number < 2) {
        printf("%c", number);
        return;
    }

    if (len >= (rightSpaces)) {
        str[number - 2] = '\0';
    }

    for (size_t i = 0; i < 3; i++) {
        if (i == 0 || i == 2) {
            printf("%c", border);
        } else {
            for (size_t j = 0; j < leftSpaces; j++) {
                printf(" ");
            }
            printf("%s", str);
            for (size_t j = 0; j < rightSpaces; j++) {
                printf(" ");
            }
        }
    }
    printf("\n");
}

