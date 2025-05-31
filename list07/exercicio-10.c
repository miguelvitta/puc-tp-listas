#include <ctype.h>
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

typedef struct {
    person** persons;
    int numPeople;
    int maxNumber;
} agenda;

agenda* createAgenda();
person* createPerson(long long int cpf, char* name, int day, int month,
                     int year, float height, float weight);
int insertPerson(agenda* a, person* p);
person* searchByCpf(agenda* a, long long int cpf);
int removeByCpf(agenda* a, long long int cpf);
void printInfo(person* p);
void printAgenda(agenda* a);
int getContactCount(agenda* a);
int getAvailableSpaces(agenda* a);
void printAverages(agenda* a);

int main() {
    agenda* myAgenda = createAgenda();
    char option = '0';
    printf(
        "This program manages a contact agenda with up to 10 people. You can "
        "add, search, remove, and view contacts by CPF.\n");

    do {
        printf(
            "\n==== AGENDA MENU ====\n"
            "I - Create and Insert Person\n"
            "C - Search Person by CPF\n"
            "R - Remove Person by CPF\n"
            "L - Print All Persons\n"
            "Q - Count Contacts\n"
            "V - Count Available Spaces\n"
            "M - Print Average of Weight, of Height and of Age of Everyone\n"
            "X - Exit\n"
            "Choose an option: ");
        scanf("%c", &option);
        option = toupper(option);
        getchar();

        switch (option) {
            case 'I': {
                long long int cpf = 0;
                char name[NAME_SIZE];
                int day = 0;
                int month = 0;
                int year = 0;
                float height = 0;
                float weight = 0;

                printf("CPF: ");
                scanf("%lld", &cpf);
                getchar();

                printf("Name: ");
                fgets(name, NAME_SIZE, stdin);
                name[strcspn(name, "\n")] = '\0';

                printf("Birth Date (dd/mm/yyyy): ");
                scanf("%d/%d/%d", &day, &month, &year);

                printf("Height (cm): ");
                scanf("%f", &height);

                printf("Weight (kg): ");
                scanf("%f", &weight);
                getchar();

                person* p =
                    createPerson(cpf, name, day, month, year, height, weight);
                if (insertPerson(myAgenda, p) != 0) {
                    printf("Person inserted successfully.\n");
                } else {
                    printf("Agenda is full. Cannot insert person.\n");
                    free(p->name);
                    free(p);
                }
                break;
            }

            case 'C': {
                long long int cpf = 0;
                printf("Enter CPF to search: ");
                scanf("%lld", &cpf);
                getchar();

                person* p = searchByCpf(myAgenda, cpf);
                if (p != NULL) {
                    printInfo(p);
                } else {
                    printf("Person not found.\n");
                }
                break;
            }

            case 'R': {
                long long int cpf = 0;
                printf("Enter CPF to remove: ");
                scanf("%lld", &cpf);
                getchar();

                if (removeByCpf(myAgenda, cpf) != 0) {
                    printf("Person removed successfully.\n");
                } else {
                    printf("Person not found.\n");
                }
                break;
            }

            case 'L':
                printAgenda(myAgenda);
                break;

            case 'Q':
                printf("Number of contacts: %d\n", getContactCount(myAgenda));
                break;

            case 'V':
                printf("Available spaces: %d\n", getAvailableSpaces(myAgenda));
                break;

            case 'M':
                printAverages(myAgenda);
                break;

            case 'X':
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid option. Try again.\n");
        }

    } while (option != 'X');

    for (int i = 0; i < myAgenda->maxNumber; i++) {
        if (myAgenda->persons[i] != NULL) {
            free(myAgenda->persons[i]->name);
            free(myAgenda->persons[i]);
        }
    }
    free(myAgenda->persons);
    free(myAgenda);

    return 0;
}

agenda* createAgenda() {
    agenda* a = NULL;
    a = malloc(sizeof(agenda));

    int number = 0;
    printf("How many people will be in this agenda?\n");
    scanf("%d", &number);
    getchar();

    a->persons = malloc(number * sizeof(person*));
    for (int i = 0; i < number; i++) {
        a->persons[i] = NULL;
    }

    a->numPeople = 0;
    a->maxNumber = number;
    return a;
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

int insertPerson(agenda* a, person* p) {
    for (int i = 0; i < a->maxNumber; i++) {
        if (a->persons[i] == NULL) {
            a->persons[i] = p;
            a->numPeople++;
            return 1;
        }
    }
    return 0;
}

person* searchByCpf(agenda* a, long long int cpf) {
    for (int i = 0; i < a->maxNumber; i++) {
        if (a->persons[i] != NULL && a->persons[i]->cpf == cpf) {
            return a->persons[i];
        }
    }
    return NULL;
}

int removeByCpf(agenda* a, long long int cpf) {
    for (int i = 0; i < a->maxNumber; i++) {
        if (a->persons[i] != NULL && a->persons[i]->cpf == cpf) {
            free(a->persons[i]->name);
            free(a->persons[i]);
            a->persons[i] = NULL;
            a->numPeople--;
            return 1;
        }
    }
    return 0;
}

void printInfo(person* p) {
    printf(
        "CPF: %011lld | Name: %s | Birth: %02d/%02d/%04d | Height: %.1f cm | "
        "Weight: %.1f kg\n",
        p->cpf, p->name, p->birthDate.day, p->birthDate.month,
        p->birthDate.year, p->height, p->weight);
}

void printAgenda(agenda* a) {
    for (int i = 0; i < a->maxNumber; i++) {
        if (a->persons[i] != NULL) {
            printInfo(a->persons[i]);
            printf("\n");
        }
    }
}

int getContactCount(agenda* a) { return a->numPeople; }

int getAvailableSpaces(agenda* a) { return a->maxNumber - a->numPeople; }

void printAverages(agenda* a) {
    if (a->numPeople == 0) {
        printf("No people in the agenda to calculate averages.\n");
        return;
    }

    float totalWeight = 0;
    float totalHeight = 0;
    int totalAge = 0;

    int currentDay = 31;
    int currentMonth = 5;
    int currentYear = 2025;

    for (int i = 0; i < a->maxNumber; i++) {
        if (a->persons[i] != NULL) {
            totalWeight += a->persons[i]->weight;
            totalHeight += a->persons[i]->height;

            int age = currentYear - a->persons[i]->birthDate.year;
            if (currentMonth < a->persons[i]->birthDate.month ||
                (currentMonth == a->persons[i]->birthDate.month &&
                 currentDay < a->persons[i]->birthDate.day)) {
                age--;
            }
            totalAge += age;
        }
    }

    float avgWeight = totalWeight / (float)a->numPeople;
    float avgHeight = totalHeight / (float)a->numPeople;
    float avgAge = (float)totalAge / (float)a->numPeople;

    printf(
        "Average Weight: %.2f kg\n"
        "Average Height: %.2f cm\n"
        "Average Age: %.2f years\n",
        avgWeight, avgHeight, avgAge);
}
