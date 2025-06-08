#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_NAME_LENGTH 101

double calculateTotalPurchase(FILE *file);
int parseProductLine(char *line, char *productName, int *quantity,
                     double *unitPrice);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr,
                "When executing the program, use the format: \"./exercicio 07 "
                "filename\"\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        fprintf(stderr, "Error opening file '%s'.\n", argv[1]);
        return 1;
    }

    double totalPurchase = calculateTotalPurchase(file);
    printf("Total purchase amount: $%.2f\n", totalPurchase);

    fclose(file);
    return 0;
}

double calculateTotalPurchase(FILE *file) {
    char line[MAX_LINE_LENGTH];
    char productName[MAX_NAME_LENGTH];
    int quantity = 0;
    double unitPrice = 0;
    double total = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        if (parseProductLine(line, productName, &quantity, &unitPrice)) {
            total += quantity * unitPrice;
        } else {
            printf("Ignored line (invalid format): %s\n", line);
        }
    }

    return total;
}

int parseProductLine(char *line, char *productName, int *quantity,
                     double *unitPrice) {
    // lets use this function onwards instead of my own custom function
    // this also handles possible multiple \n better than my own custom
    // implementation
    line[strcspn(line, "\n")] = '\0';

    char *token = strtok(line, ",");
    if (token == NULL) {
        return 0;
    }
    strcpy(productName, token);

    // remember that the NULL is to use the property of starting where it left
    // off it uses a static internal pointer between functions
    // that's why the linter says it's not thread safe
    // as it doesn't handle different concurrent uses for different delimiters
    token = strtok(NULL, ",");
    if (token == NULL) {
        return 0;
    }
    *quantity = atoi(token);

    token = strtok(NULL, ",");
    if (token == NULL) {
        return 0;
    }
    *unitPrice = atof(token);

    return 1;
}
