#include <stdio.h>

int determineVowel(char c);

int main() {
    char c = '\0';
    
    printf("Write the character you want to test if it's a lowercase vowel: ");
    scanf("%c", &c);

    int result = determineVowel(c);

    if (result == 1) {
        printf("The character is a lowercase vowel.\n");
    } else {
        printf("The character is not a lowercase vowel.\n");
    }

    return 0;
}

int determineVowel(char c) {
    if (c == 97 || c == 101 || c == 105 || c == 111 || c == 117) {
        return 1;
    }

    return 0;
}


