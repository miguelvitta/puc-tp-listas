#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* pfile = NULL;
    int ch;

    pfile = fopen("arq.txt", "r");
    if (pfile == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    while ((ch = fgetc(pfile)) != EOF) {
        printf("%c", ch);
    }

    fclose(pfile);
    
    return 0;
}