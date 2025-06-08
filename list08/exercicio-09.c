#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 101

typedef struct {
    char name[MAX_NAME_SIZE];
    float weight;
    float height;
} patient;

void insertPatient(const char* filename);
float calculateIMC(float weight, float height);
void listPatients(const char* filename);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr,
                "When executing the program, use the format: \"./exercicio 09 "
                "\"filename\" (the file to be created) \n");
        return 1;
    }

    int option = -1;
    while (option != 0) {
        printf(
            "\nSelect an option:\n"
            "  1 - Insert new patient record\n"
            "  2 - List records by filter\n"
            "  0 - Exit the program\n"
            "Enter your choice: ");
        scanf("%d", &option);
        getchar();

        switch (option) {
            case 1:
                insertPatient(argv[1]);
                break;
            case 2:
                listPatients(argv[1]);
                break;
            case 0:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}

void insertPatient(const char* filename) {
    patient p;

    printf("Name: ");
    fgets(p.name, MAX_NAME_SIZE, stdin);
    p.name[strcspn(p.name, "\n")] = '\0';

    printf("Weight (in kilograms): ");
    scanf("%f", &p.weight);
    getchar();

    printf("Height (in meters): ");
    scanf("%f", &p.height);
    getchar();

    FILE* pfile = fopen(filename, "ab");
    if (pfile == NULL) {
        fprintf(stderr, "Error opening file '%s'.\n", filename);
        return;
    }

    fwrite(&p, sizeof(patient), 1, pfile);

    fclose(pfile);

    printf("Patient added successfully!\n");
}

float calculateIMC(float weight, float height) {
    if (height <= 0) {
        return 0;
    }
    return weight / (height * height);
}

void listPatients(const char* filename) {
    int filter = 0;
    float minVal = 0;
    float maxVal = 0;

    printf(
        "\nChoose filter type:\n"
        "  1 - Weight range\n"
        "  2 - Height range\n"
        "  3 - BMI range\n"
        "Enter your choice: ");
    scanf("%d", &filter);
    getchar();

    printf("Minimum filter value: ");
    scanf("%f", &minVal);
    getchar();

    printf("Maximum filter value: ");
    scanf("%f", &maxVal);
    getchar();

    FILE* pfile = fopen(filename, "rb");
    if (pfile == NULL) {
        fprintf(stderr, "Error opening file '%s'.\n", filename);
        return;
    }

    patient p;
    int status = 0;

    printf("\nPatients status:\n");
    while (fread(&p, sizeof(patient), 1, pfile) == 1) {
        float filterValue = 0;

        switch (filter) {
            case 1:
                filterValue = p.weight;
                break;
            case 2:
                filterValue = p.height;
                break;
            case 3:
                filterValue = calculateIMC(p.weight, p.height);
                break;
            default:
                printf("Invalid filter!\n");
                fclose(pfile);
                return;
        }

        if (filterValue >= minVal && filterValue <= maxVal) {
            printf("Name: %s, Weight: %.2f kg, Height: %.2f m, IMC: %.2f\n",
                   p.name, p.weight, p.height,
                   calculateIMC(p.weight, p.height));
            status = 1;
        }
    }

    if (!status) {
        printf("No patients found for the specified filter.\n");
    }

    fclose(pfile);
}
