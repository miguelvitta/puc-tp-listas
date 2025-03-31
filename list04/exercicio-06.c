#include <stdio.h>
#include <stdlib.h>

#define SIZE_STRING 1001
#define UPPER_CASE_A 65
#define UPPER_CASE_Z 90
#define LOWER_CASE_A 97
#define LOWER_CASE_Z 122
#define CASE_OFFSET 32

void getString(char* str);
size_t stringLength(const char* str);
size_t removeTrailing(size_t len, char* str);
void changeCases(char* str);

int main() {
    char* str1 = NULL;
    str1 = malloc(sizeof(char) * SIZE_STRING);
    if (str1 == NULL) {
        fprintf(stderr, "Memory allocation has failed\n");
        return 1;
    }

    printf(
        "This program will receive a string and change the cases of words. "
        "UPPER to lower case, and vice-versa.\n");

    getString(str1);

    changeCases(str1);

    printf("%s\n", str1);

    free(str1);
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

void changeCases(char* str) {
    size_t len = stringLength(str);

    for (size_t i = 0; i < len; i++) {
        if (str[i] >= UPPER_CASE_A && str[i] <= UPPER_CASE_Z) {
            str[i] += CASE_OFFSET;
        } else {
            if (str[i] >= LOWER_CASE_A && str[i] <= LOWER_CASE_Z) {
                str[i] -= CASE_OFFSET;
            }
        }
    }
}

