#include <stdio.h>
#include <stdlib.h>

#define SIZE_STRING 1001

size_t stringLength(char* str);

int main() {
    char* str = NULL;
    str = malloc(sizeof(char) * SIZE_STRING);
    if (str == NULL) {
        fprintf(stderr, "Memory allocation has failed\n");
        return 1;
    }

    printf(
        "This program has the following function. Write some text and it will "
        "return the lenght/size of the text.\n");
    printf("Write the text: ");
    fgets(str, SIZE_STRING, stdin);
    size_t len = stringLength(str);

    printf("The number of characters is: %zu\n", len);

    free(str);

    return 0;
}

size_t stringLength(char* str) {
    size_t len = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        len++;
    }
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }
    return len;
}

