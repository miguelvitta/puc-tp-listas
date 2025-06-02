#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* pfile = fopen("arq.txt", "w+");
    if (pfile == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    int ch;
    while ((ch = getchar()) != '0') {
        fputc(ch, pfile);
    }

    fclose(pfile);
    return 0;
}