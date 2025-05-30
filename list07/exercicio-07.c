#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 101

typedef struct {
    long long int cpf;
    char* name;
    struct {
        int day;
        int month;
        int year;
    } birthDate;
    float height;  // in cm
    float weight;  // in kg
} person;

person* createPerson(long long int cpf, char* name, int day, int month,
                     int year, float height, float weight);
int getWeight(person* p);
float getHeight(person* p);
int getAge(person* p);
float getIMC(person* p);
void printInfo(person* p);

int main() {
    printf(
        "This program creates a struct of a person with the following data:\n"
        "CPF, name, birth date, height and weight. Then it has the following "
        "functionalities:\n"
        "- Shows the person's weight in grams\n"
        "- Shows the person's height in meters\n"
        "- Calculates and shows the person's age\n"
        "- Calculates and shows the person's IMC\n"
        "- Shows all information about the person\n\n");

    long long int cpf = 0;
    char name[NAME_SIZE];
    int day = 0;
    int month = 0;
    int year = 0;
    float height = 0;
    float weight = 0;

    printf("Enter the following data:\n");
    printf("CPF:\n");
    scanf("%lld", &cpf);
    while (getchar() != '\n' && !feof(stdin)) {
    };

    printf("Name:\n");
    fgets(name, NAME_SIZE, stdin);
    size_t len = strlen(name);
    if (len > 0 && name[len - 1] == '\n') {
        name[len - 1] = '\0';
    }

    printf("Birth date: (format:day/month/year)\n");
    scanf("%d/%d/%d", &day, &month, &year);

    printf("Heigth: (in centimeters)\n");
    scanf("%f", &height);

    printf("Weight: (in kilograms)\n");
    scanf("%f", &weight);

    person* p = createPerson(cpf, name, day, month, year, height, weight);

    printf("The weight of the person is: %d g\n", getWeight(p));
    printf("The height of the person is: %.2f m\n", getHeight(p));
    printf("The age of this person is: %d years old\n", getAge(p));
    printf("The IMC of the person is : %.2f\n", getIMC(p));

    printInfo(p);

    free(p->name);
    free(p);
    return 0;
}

person* createPerson(long long int cpf, char* name, int day, int month,
                     int year, float height, float weight) {
    person* p = malloc(sizeof(person));
    p->name = malloc(strlen(name) + 1);
    strcpy(p->name, name);
    p->cpf = cpf;
    p->birthDate.day = day;
    p->birthDate.month = month;
    p->birthDate.year = year;
    p->height = height;
    p->weight = weight;
    return p;
}

int getWeight(person* p) { return p->weight * 1000; }

float getHeight(person* p) { return p->height / 100.0; }

int getAge(person* p) {
    int currentDay = 29;
    int currentMonth = 5;
    int currentYear = 2025;

    int age = currentYear - p->birthDate.year;
    if (currentMonth < p->birthDate.month ||
        (currentMonth == p->birthDate.month && currentDay < p->birthDate.day)) {
        age--;
    }
    return age;
}

float getIMC(person* p) {
    float heightInMeters = getHeight(p);
    return p->weight / (heightInMeters * heightInMeters);
}

void printInfo(person* p) {
    printf(
        "The information of the person are:\n"
        "CPF: %011lld | %s | %02d/%02d/%04d | %.1f cm | %.1f kg\n",
        p->cpf, p->name, p->birthDate.day, p->birthDate.month,
        p->birthDate.year, p->height, p->weight);
}