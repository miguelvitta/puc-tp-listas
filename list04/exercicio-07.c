#include <stdio.h>
#include <stdlib.h>

#define SIZE_STRING 1001

void getString(char* str);
size_t stringLength(const char* str);
size_t removeTrailing(size_t len, char* str);
char** createSubStrings(const char* str, int control, int* number);
void stringCopy(char* substring, const char* str, size_t start,
                size_t substringLength);

int main() {
    char* str1 = NULL;
    str1 = malloc(sizeof(char) * SIZE_STRING);
    if (str1 == NULL) {
        fprintf(stderr, "\nMemory allocation has failed\n");
        return 1;
    }
    printf(
        "This program receives:\na string;\na character that will serve as "
        "limit;\nand then subdivides the original string into substrings that "
        "have as limit the char you entered.\n");
    getString(str1);

    printf("Enter the character that will subdivide the string: ");
    int control = getchar();

    // this is to clean the buffer. Not Needed here, but I will put it here so I
    // get in the habit and don't forget when I need to clean it
    while (getchar() != '\n' && !feof(stdin)) {}
    int number = 0;

    char** substrings = createSubStrings(str1, control, &number);
    if (substrings == NULL) {
        fprintf(stderr, "\nMemory allocation has failed\n");
        free(str1);
        return 1;
    }

    printf("Number of strings: %d\n", number);
    for (int i = 0; i < number; i++) {
        printf("%d: \"%s\"\n", i, substrings[i]);
    }

    free(str1);
    for (int i = 0; i < number; i++) {
        free(substrings[i]);
    }
    free(substrings);
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

// This took so long..
char** createSubStrings(const char* str, int control, int* number) {
    size_t len = stringLength(str);
    int count = 1;
    for (size_t i = 0; i < len; i++) {
        if (str[i] == control) {
            count++;
        }
    }
    *number = count;

    char** result = NULL;
    result = malloc(sizeof(char*) * count);
    if (result == NULL) {
        return NULL;
    }

    size_t start = 0;
    int substringIndex = 0;
    for (size_t i = 0; i <= len; i++) {
        if (i == len || str[i] == (char)control) {
            size_t substringLength = i - start;
            char* substring = malloc((substringLength + 1) * sizeof(char));
            if (substring == NULL) {
                for (int j = 0; j < substringIndex; j++) {
                    free(result[j]);
                }
                free(result);
                *number = 0;
                return NULL;
            }
            stringCopy(substring, str, start, substringLength);
            result[substringIndex++] = substring;
            start = i + 1;
        }
    }

    return result;
}

void stringCopy(char* substring, const char* str, size_t start,
                size_t substringLength) {
    for (size_t i = 0; i < substringLength; i++) {
        substring[i] = str[start + i];
    }
    substring[substringLength] = '\0';
}

