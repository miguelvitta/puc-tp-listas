#include <stdio.h>
#include <stdlib.h>

#define SIZE_STRING 11
#define LOWER_NUMBER 48
#define HIGHER_NUMBER 57

void getString(char* str);
size_t stringLength(const char* str);
size_t removeTrailing(size_t len, char* str);
int convertStringToInt(char* str);

int main() {
    char* str1 = NULL;
    str1 = malloc(sizeof(char) * SIZE_STRING);
    if (str1 == NULL) {
        fprintf(stderr, "Memory allocation has failed\n");
        return 1;
    }
    
    printf("This program will get a positive number as a string and convert it to int.\n");

    getString(str1);

    int result = convertStringToInt(str1);
    if (result >= 0) {
        printf("%d\n", result);
    }

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

int convertStringToInt(char* str) {
    size_t len = stringLength(str);
    int number = 0;

    for (size_t i = 0; i < len; i++) {
        if (str[i] < LOWER_NUMBER || str[i] > HIGHER_NUMBER) {
            fprintf(stderr, "Only positive numbers are allowed\n");
            return -1;
        }
        number = number * 10 + (str[i] - '0');
    }
    return number;
}

