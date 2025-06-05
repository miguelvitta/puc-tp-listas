#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    char choice = '0';

    printf("Enter 'U' for uppercase and 'l' for lowercase:\n");
    scanf("%c", &choice);
    getchar();

    int ch = 0;
    switch (choice) {
        case 'l':
            while ((ch = fgetc(pfile1)) != EOF) {
                char lower = tolower(ch);
                fputc(lower, pfile2);
            }
            break;
        case 'U':
            while ((ch = fgetc(pfile1)) != EOF) {
                char upper = toupper(ch);
                fputc(upper, pfile2);
            }
            break;
    }
    fclose(pfile1);
    fclose(pfile2);

    return 0;
}