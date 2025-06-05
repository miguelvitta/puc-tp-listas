#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[100];
    printf("Enter the filename:\n");
    scanf("%99s", filename);
    getchar();

    char control = '0';
    printf("Enter a character:\n");
    scanf("%c", &control);

    FILE* pfile = NULL;

    pfile = fopen(filename, "r");
    if (pfile == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    int ch = 0;
    int count = 0;
    while ((ch = fgetc(pfile)) != EOF) {
        if (ch == control) {
            count++;
        }
    }

    printf("The \"%c\" character appears %d times in this file.\n", control, count);

    fclose(pfile);

    return 0;
}