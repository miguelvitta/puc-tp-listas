#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int copyFileContents(FILE *source, FILE *destination);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr,
                "When executing the program, use the format: \"./exercicio 08 "
                "\"filename\" (the first file to be copied) \"filename\" (the "
                "second file to be copied) \"filename\" (the file to be "
                "created)\n");
        return 1;
    }
    FILE *pfile1 = fopen(argv[1], "r");
    if (pfile1 == NULL) {
        fprintf(stderr, "Error opening file '%s'.\n", argv[1]);
        return 1;
    }

    FILE *pfile2 = fopen(argv[2], "r");
    if (pfile2 == NULL) {
        fprintf(stderr, "Error opening file '%s'.\n", argv[2]);
        fclose(pfile1);
        return 1;
    }

    FILE *pfile3 = fopen(argv[3], "w+");
    if (pfile3 == NULL) {
        fprintf(stderr, "Error opening file '%s'.\n", argv[3]);
        fclose(pfile1);
        fclose(pfile2);
        return 1;
    }

    copyFileContents(pfile1, pfile3);
    fprintf(pfile3, "\n");
    copyFileContents(pfile2, pfile3);

    fclose(pfile1);
    fclose(pfile2);
    fclose(pfile3);
    return 0;
}

int copyFileContents(FILE *source, FILE *destination) {
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, source) != NULL) {
        fputs(buffer, destination);
    }
    return 0;
}