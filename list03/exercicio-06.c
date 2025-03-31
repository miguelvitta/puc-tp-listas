#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1001
#define ASCII_OFFSET 97

void getString(char* str);
size_t removeTrailing(size_t n, char* str);
void toUpperCase(char* str1, char* str2);

int main() {
    char* string1 = NULL;
    string1 = (char*)malloc(sizeof(char) * SIZE);
    if (string1 == NULL) {
        fprintf(stderr, "Memory allocation has failed\n");
        return 1;
    }

    getString(string1);

    char* string2 = NULL;
    string2 = (char*)malloc(sizeof(char) * SIZE);
    if (string2 == NULL) {
        free(string1);
        fprintf(stderr, "Memory allocation has failed\n");
        return 1;
    }

    toUpperCase(string1, string2);

    printf("The original string is: %s\nThe new string is: %s\n", string1,
           string2);

    free(string1);
    free(string2);
    return 0;
}

void getString(char* str) {
    printf("Enter the string: ");
    if (fgets(str, SIZE, stdin) != NULL) {
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

void toUpperCase(char* str1, char* str2) {
    size_t len = strlen(str1);

    for (size_t i = 0; i < len; i++) {
        str2[i] = str1[i];
        if (str2[i] - ASCII_OFFSET >= 0 && str2[i] - ASCII_OFFSET <= 25) {
            str2[i] -= 32;
        }
    }
    str2[len] = '\0';
}

