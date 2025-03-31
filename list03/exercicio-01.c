#include <stdio.h>

int determineConsonant(char c);

int main() {
    char c = '\0';
    
    printf("Write the character you want to test if it's a consonant: ");
    scanf("%c", &c);

    int result = determineConsonant(c);

    if (result == 1) {
        printf("The character is a consonant.\n");
    } else {
        printf("The character is not a consonant.\n");
    }

    return 0;
}

int determineConsonant(char c) {
    if ((c >= 66 && c <= 68) || (c >= 70 && c <= 72) || (c >= 74 && c <= 78) ||
        (c >= 80 && c <= 84) || (c >= 86 && c <= 90) || (c >= 98 && c <= 100) ||
        (c >= 102 && c <= 104) || (c >= 106 && c <= 110) ||
        (c >= 112 && c <= 116) || (c >= 118 && c <= 122)) {
        return 1;
    }

    return 0;
}

