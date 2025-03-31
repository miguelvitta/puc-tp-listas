#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1001

void getString(char* str);
size_t removeTrailing(size_t n, char* str);
int testPalindrome(char* str);

int main() {
    char* string = NULL;
    string = (char*)malloc(sizeof(int) * SIZE);
    if (string == NULL) {
        fprintf(stderr, "Memory allocation has failed\n");
        return 1;
    }

    getString(string);

    int result = testPalindrome(string);

    if (result == 1) {
        printf("This string is a palindrome.\n");
    } else {
        printf("This string is not a palindrome.\n");
    }

    free(string);

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

int testPalindrome(char* str) {
    size_t len = strlen(str);
    char test[SIZE];
    for (size_t i = 0; i < len; i++) {
        test[i] = str[len - i - 1];
    }
    test[len] = '\0';

    for (size_t i = 0; i < len; i++) {
        if (test[i] != str[i]) {
            return 0;
        }
    }
    return 1;
}

