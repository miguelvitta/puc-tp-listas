#include <stdio.h>
#include <stdlib.h>

#define SIZE_STRING 1001

void getString(char* str);
size_t stringLength(const char* str);
size_t removeTrailing(size_t len, char* str);
int findSubString(char* str1, char* str2);

int main() {
    char* str1 = NULL;
    str1 = malloc(sizeof(char) * SIZE_STRING);
    if (str1 == NULL) {
        fprintf(stderr, "\nMemory allocation has failed\n");
        return 1;
    }
    printf(
        "This program receives two strings, searches the first string for the "
        "first place where the second string can be found, then returns the "
        "index where this occurrence starts\n");
    getString(str1);

    char* str2 = NULL;
    str2 = malloc(sizeof(char) * SIZE_STRING);
    if (str2 == NULL) {
        fprintf(stderr, "\nMemory allocation has failed\n");
        free(str1);
        return 1;
    }

    getString(str2);

    int result = findSubString(str1, str2);

    if (result >= 0) {
        printf("The index of the substring is: %d\n", result);
    } else {
        printf("There is no occurrence of the substring in the first one\n");
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

int findSubString(char* str1, char* str2) {
    size_t len1 = stringLength(str1);
    size_t len2 = stringLength(str2);

    int result = -1;
    size_t count = 0;
    int valid = 0;

    for (size_t i = 0, j = 0; i < len1; i++) {
        if (str2[j] == str1[i] && valid == 0) {
            count++;
            j++;
        } else {
            if (str2[i] != str1[i] && valid == 0) {
                count = 0;
                j = 0;
                result = -1;
            }
        }
        if (count == len2 && valid == 0) {
            result = (int)i - (int)len2 + 1;
            valid = 1;
        }
    }

    return result;
}

