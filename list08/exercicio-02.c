#include <stdio.h>
#include <stdlib.h>

int main() {

    char filename[100];
    printf("Enter the filename: ");
    scanf("%99s", filename);

    FILE* pfile = NULL;
    int ch;

    pfile = fopen(filename, "r");
    if (pfile == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    int lines = 0;
    while ((ch = fgetc(pfile)) != EOF) {
        if (ch == '\n') {
            lines++;
        };
    }

    printf("%d\n", lines);

    fclose(pfile);
    
    return 0;
}