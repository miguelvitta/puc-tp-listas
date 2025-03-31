#include <stdio.h>
#include <stdlib.h>

#define SIZE_STRING 1001

void getString(char* str);
size_t stringLength(const char* str);
size_t removeTrailing(size_t len, char* str);
void formatString(char* str1, char* str2);

int main() {
    char* str1 = NULL;
    str1 = malloc(sizeof(char) * SIZE_STRING);
    if (str1 == NULL) {
        fprintf(stderr, "Memory allocation has failed\n");
        return 1;
    }
    printf(
        "This program has the following function. Write some text and it will "
        "remove whitespaces and tabs before the first character and also after "
        "the last character.\n");
    getString(str1);

    char* str2 = NULL;
    str2 = malloc(sizeof(char) * SIZE_STRING);
    if (str2 == NULL) {
        fprintf(stderr, "Memory allocation has failed\n");
        free(str1);
        return 1;
    }

    formatString(str1, str2);

    printf("\"%s\"\n", str2);

    free(str1);
    free(str2);
    return 0;
}

void getString(char* str) {
    int valid = 0;
    while (!valid) {
        printf("Enter the string: ");
        if (fgets(str, SIZE_STRING, stdin) != NULL) {
            size_t len = stringLength(str);
            len = removeTrailing(len, str);
            if (len > 0) {
                valid = 1;
            } else {
                fprintf(stderr, "\nInput cannot be empty. Try again: ");
            }
        } else {
            fprintf(stderr, "\nError reading the string.\n");
        }
    }
}

size_t stringLength(const char* str) {
    size_t len = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        len++;
    }
    return len;
}

size_t removeTrailing(size_t len, char* str) {
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }
    return len;
}

/*
Horizontal Tab (‘\t’): ASCII 9
Newline (‘\n’): ASCII 10
Carriage Return (‘\r’): ASCII 13
Space (‘ ’): ASCII 32
*/

void formatString(char* str1, char* str2) {
    size_t len = stringLength(str1);

    for (size_t i = len - 1; i > 0 && (str1[i] == 9 || str1[i] == 10 ||
                                       str1[i] == 13 || str1[i] == 32);
         i--) {
        str1[i] = '\0';
        len--;
    }

    size_t start = 0;
    for (size_t i = 0; i < len && (str1[i] == 9 || str1[i] == 10 ||
                                   str1[i] == 13 || str1[i] == 32);
         i++) {
        start = i + 1;
    }

    for (size_t i = 0, j = start; i < len; i++, j++) {
        str2[i] = str1[j];
    }
}

