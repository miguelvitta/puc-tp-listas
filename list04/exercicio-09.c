#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_STRING 1001

void getString(char* str);
size_t stringLength(const char* str);
size_t removeTrailing(size_t len, char* str);
char* sumBigNumbers(char* str1, char* str2);

int main() {
    char* str1 = NULL;
    str1 = malloc(sizeof(char) * SIZE_STRING);
    if (str1 == NULL) {
        fprintf(stderr, "\nMemory allocation has failed\n");
        return 1;
    }
    printf(
        "This program receives two numbers as strings and gives the sum of "
        "both as a string too. It can handle very big numbers.\n");
    getString(str1);

    char* str2 = NULL;
    str2 = malloc(sizeof(char) * SIZE_STRING);
    if (str2 == NULL) {
        fprintf(stderr, "\nMemory allocation has failed\n");
        free(str1);
        return 1;
    }

    getString(str2);

    char* result = sumBigNumbers(str1, str2);

    if (result == NULL) {
        fprintf(stderr, "\nMemory allocation has failed\n");
        free(str1);
        free(str2);
        return 1;
    }

    printf("%s\n", result);

    free(str1);
    free(str2);
    free(result);
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

char* sumBigNumbers(char* str1, char* str2) {
    size_t len1 = stringLength(str1);
    size_t len2 = stringLength(str2);
    size_t maxLen = (len1 > len2 ? len1 : len2);

    char* str3 = NULL;
    // + 2, +1 for the \0 and +1 for the possible extra digit
    str3 = malloc(sizeof(char) * (maxLen + 2));
    if (str3 == NULL) {
        return NULL;
    }
    str3[maxLen + 1] = '\0';

    int i = (int)len1 - 1;
    int j = (int)len2 - 1;
    int k = (int)maxLen;
    size_t carry = 0;

    // My God, how long till I realized that I could simply  use OR between the
    // conditions instead of a big while with conditions inside
    while (i >= 0 || j >= 0 || carry > 0) {
        // conditional inside to take care of the sum of strings that were
        // already over
        size_t digit1 = (i >= 0) ? (str1[i] - '0') : 0;
        size_t digit2 = (j >= 0) ? (str2[j] - '0') : 0;
        size_t sum = digit1 + digit2 + carry;
        carry = sum / 10;
        str3[k] = (sum % 10) + '0';
        k--;

        if (i >= 0) {
            i--;
        }
        if (j >= 0) {
            j--;
        }
    }

    // checking for extra digit
    char* start = &str3[k + 1];
    if (start == str3) {
        return str3;
    }
    // I was using another variables till I realized that I could simply reuse k
    // for the check above and for the new length
    size_t resultLen = maxLen - k;
    char* finalResult = malloc(resultLen + 1);
    if (finalResult == NULL) {
        free(str3);
        return NULL;
    }
    // I would like to make my own custo strcpy, but this list is already too
    // late, so let me finish this already
    strcpy(finalResult, start);
    free(str3);
    return finalResult;
}

