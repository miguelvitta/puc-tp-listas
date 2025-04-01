#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_STRING 1001

char classificarSenha(char* str);

int main() {
    char* str = NULL;
    str = malloc(sizeof(char) * SIZE_STRING);

    fgets(str, SIZE_STRING, stdin);
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    char result = classificarSenha(str);

    printf("The password is of %c\n", result);

    free(str);
    return 0;
}

char classificarSenha(char* str) {
    size_t len = strlen(str);

    int points = 0;
    if (len >= 8) {
        points++;
    }
    int lowercase = 0;
    int uppercase = 0;
    int hasnumber = 0;
    int specialchar = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            lowercase = 1;
        }
        if (str[i] >= 'A' && str[i] <= 'Z') {
            uppercase = 1;
        }
        if (str[i] >= '0' && str[i] <= '9') {
            hasnumber = 1;
        }
        if (str[i] == '@' || str[i] == '#' || str[i] == '$'|| str[i] == '&' || str[i] == '*') {
            specialchar = 1;
        }
    }

    points = points + lowercase + uppercase + hasnumber + specialchar;

    char result = '\0';

    if (points == 5) {
        result = 'A';
    }
    else {
        if (points == 3 || points == 4) {
            result = 'B';
        }
        else {
            if (points < 3) {
                result = 'C';
            }
        }
    }
    return result;
}