#include <stdio.h>
#include <stdlib.h>

#define SIZE_STRING 1001

void getString(char* str);
size_t stringLength(const char* str);
size_t removeTrailing(size_t len, char* str);
char* concatenateStrings(char* str1, char* str2);

int main() {
    char* str1 = NULL;
    str1 = malloc(sizeof(char) * SIZE_STRING);
    if (str1 == NULL) {
        fprintf(stderr, "Memory allocation has failed\n");
        return 1;
    }
    printf("This program gets two separate strings and concatenate them.\n");
    getString(str1);

    char* str2 = NULL;
    str2 = malloc(sizeof(char) * SIZE_STRING);
    if (str2 == NULL) {
        fprintf(stderr, "Memory allocation has failed\n");
        free(str1);
        return 1;
    }
    getString(str2);

    char* result = concatenateStrings(str1, str2);
    if (result != NULL) {
        printf("%s\n", result);
        free(result);
    }

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

char* concatenateStrings(char* str1, char* str2) {
    char* str3 = NULL;
    str3 = malloc(sizeof(char) * SIZE_STRING);
    if (str3 == NULL) {
        fprintf(stderr, "Memory allocation has failed\n");
        return NULL;
    }

    size_t len1 = stringLength(str1);
    size_t len2 = stringLength(str2);
    size_t len3 = len1 + len2;

    for (size_t i = 0, j = 0; i < len3; i++) {
        if (i < len1) {
            str3[i] = str1[i];
        } else {
            str3[i] = str2[j];
            j++;
        }
    }

    return str3;
}

