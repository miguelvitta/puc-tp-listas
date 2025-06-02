#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[100];
    printf("Enter the filename: ");
    scanf("%99s", filename);

    FILE* pfile = NULL;
    int ch = 0;

    pfile = fopen(filename, "r");
    if (pfile == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    int vowels = 0;
    int consonants = 0;
    while ((ch = fgetc(pfile)) != EOF) {
        if (ch >= 65 && ch <= 90) {
            if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                vowels++;
            } else {
                consonants++;
            }
        } else if (ch >= 97 && ch <= 122) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }

    printf(
        "The number of vowes is %d\n"
        "The number of consonants is: %d\n",
        vowels, consonants);

    fclose(pfile);

    return 0;
}