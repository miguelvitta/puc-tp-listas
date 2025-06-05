#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isvowel(int ch);

int main() {
    char filename1[100];
    printf("Enter the filename:\n");
    scanf("%99s", filename1);
    getchar();

    char filename2[100];
    printf("Enter the filename for the new text file:\n");
    scanf("%99s", filename2);
    getchar();

    FILE* pfile1 = NULL;
    FILE* pfile2 = NULL;

    pfile1 = fopen(filename1, "r");
    if (pfile1 == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    pfile2 = fopen(filename2, "w+");
    if (pfile2 == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    int ch = 0;
    while ((ch = fgetc(pfile1)) != EOF) {
        if (isvowel(ch)) {
            ch = '*';
        }
        fputc(ch, pfile2);
    }

    fclose(pfile1);
    fclose(pfile2);

    return 0;
}

int isvowel(int ch) {
    int c = toupper(ch);
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        return 1;
    }
    return 0;
}