#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_STRING 10001
#define SIZE_INT 14

int getInt();
void getString(char* str);

int main(int argc, char* argv[]) {

    printf("This program has the following functions:\n");

    return 0;
}

static size_t removeTrailing(size_t len, char* str) {
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }
    return len;
}

int getInt() {
    int n = 0;
    char buffer[SIZE_INT];
    if (fgets(buffer, SIZE_INT, stdin) != NULL) {
        size_t len = strlen(buffer);
        len = removeTrailing(len, buffer);

        for (size_t i = 0; i < len; i++) {
            if (!isdigit(buffer[i])) {
                fprintf(stderr, "\nThis is not a valid number.\n");
                return -1;
            }
            n = n * 10 + (buffer[i] - '0');
            if (n < 0) {
                fprintf(stderr, "\nNumber is too large.\n");
                return -2;
            }
        }
    }
    return n;
}

void getString(char* str) {
    int valid = 0;
    while (!valid) {
        printf("Enter the string: ");
        if (fgets(str, SIZE_STRING, stdin) != NULL) {
            size_t len = strlen(str);
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

