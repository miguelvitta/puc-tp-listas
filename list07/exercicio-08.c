#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 101
#define NUMBER_PEOPLE 10

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
    person* persons[NUMBER_PEOPLE];
    int numPeople;
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

int main() {
    agenda* myAgenda = createAgenda();
    int option = 0;
    printf(
        "This program manages a contact agenda with up to 10 people. You can "
        "add, search, remove, and view contacts by CPF.\n");

    do {
        printf("\n==== AGENDA MENU ====\n");
        printf("1 - Create and Insert Person\n");
        printf("2 - Search Person by CPF\n");
        printf("3 - Remove Person by CPF\n");
        printf("4 - Print All Persons\n");
        printf("5 - Count Contacts\n");
        printf("6 - Count Available Spaces\n");
        printf("0 - Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);
        getchar();

        switch (option) {
            case 1: {
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

            case 2: {
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

            case 3: {
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

            case 4:
                printAgenda(myAgenda);
                break;

            case 5:
                printf("Number of contacts: %d\n", getContactCount(myAgenda));
                break;

            case 6:
                printf("Available spaces: %d\n", getAvailableSpaces(myAgenda));
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid option. Try again.\n");
        }

    } while (option != 0);

    for (int i = 0; i < NUMBER_PEOPLE; i++) {
        if (myAgenda->persons[i] != NULL) {
            free(myAgenda->persons[i]->name);
            free(myAgenda->persons[i]);
        }
    }
    free(myAgenda);

    return 0;
}

agenda* createAgenda() {
    agenda* a = NULL;
    a = malloc(sizeof(agenda));

    for (int i = 0; i < NUMBER_PEOPLE; i++) {
        a->persons[i] = NULL;
    }

    a->numPeople = 0;
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
    for (int i = 0; i < NUMBER_PEOPLE; i++) {
        if (a->persons[i] == NULL) {
            a->persons[i] = p;
            a->numPeople++;
            return 1;
        }
    }
    return 0;
}

person* searchByCpf(agenda* a, long long int cpf) {
    for (int i = 0; i < NUMBER_PEOPLE; i++) {
        if (a->persons[i] != NULL && a->persons[i]->cpf == cpf) {
            return a->persons[i];
        }
    }
    return NULL;
}

int removeByCpf(agenda* a, long long int cpf) {
    for (int i = 0; i < NUMBER_PEOPLE; i++) {
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
    for (int i = 0; i < NUMBER_PEOPLE; i++) {
        if (a->persons[i] != NULL) {
            printInfo(a->persons[i]);
            printf("\n");
        }
    }
}

int getContactCount(agenda* a) { return a->numPeople; }

int getAvailableSpaces(agenda* a) { return NUMBER_PEOPLE - a->numPeople; }
