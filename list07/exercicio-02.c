#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int currentFloor;
    int totalFloors;
    int capacity;
    int currentPeople;
} Elevator;

Elevator* createElevator(int totalFloors, int capacity);
int enterElevator(Elevator* e, int numberOfPeople);
int exitElevator(Elevator* e, int numberOfPeople);
int goUp(Elevator* e, int numberOfFloors);
int goDown(Elevator* e, int numberOfFloors);

int main() {
    printf(
        "This program simulates an elevator system in a building.\n"
        "It defines a structure to represent the elevator and implements "
        "functions to:\n"
        "  1. Create a new elevator with a specified number of floors and "
        "capacity.\n"
        "  2. Add people to the elevator (if capacity allows).\n"
        "  3. Remove people from the elevator (if enough people are inside).\n"
        "  4. Move the elevator up (if within building limits).\n"
        "  5. Move the elevator down (if not below ground floor).\n"
        "\n"
        "Rules:\n"
        "  - Floor 0 is the ground floor (no basements).\n"
        "  - The elevator starts at the ground floor with no one inside.\n"
        "  - Operations will only succeed if the conditions are met, otherwise "
        "the elevator remains unchanged.\n");

    int totalFloors = 0;
    printf("Enter the number of floors above the ground floor:\n");
    scanf("%d", &totalFloors);

    int capacity = 0;
    printf("Enter the maximum capacity of the elevator:\n");
    scanf("%d", &capacity);

    if (totalFloors < 1 || capacity < 1) {
        fprintf(stderr, "Invalid input: both values must be positive.\n");
        return 1;
    }

    Elevator* e = NULL;
    e = createElevator(totalFloors, capacity);

    int numberOfPeople = 0;
    printf("Enter the number of people entering the elevator:\n");
    scanf("%d", &numberOfPeople);
    int confirmation = enterElevator(e, numberOfPeople);
    if (confirmation == 0) {
        fprintf(stderr,
                "Error: elevator cannot accommodate that many people.\n");
        free(e);
        return 1;
    }

    printf("Enter the number of people exiting the elevator:\n");
    scanf("%d", &numberOfPeople);
    confirmation = exitElevator(e, numberOfPeople);
    if (confirmation == 0) {
        fprintf(stderr, "Error: not enough people in the elevator to exit.\n");
        free(e);
        return 1;
    }

    int numberOfFloors = 0;
    printf("Enter the number of floors to move up:\n");
    scanf("%d", &numberOfFloors);
    confirmation = goUp(e, numberOfFloors);
    if (confirmation == 0) {
        fprintf(stderr,
                "Error: the building does not have that many floors above.\n");
        free(e);
        return 1;
    }

    printf("Enter the number of floors to move down:\n");
    scanf("%d", &numberOfFloors);
    confirmation = goDown(e, numberOfFloors);
    if (confirmation == 0) {
        fprintf(stderr, "Error: cannot move below the ground floor.\n");
        free(e);
        return 1;
    }

    printf("Final status:\n");
    printf("\tCurrent floor: %d\n", e->currentFloor);
    printf("\tPeople in elevator: %d\n", e->currentPeople);

    free(e);
    return 0;
}

Elevator* createElevator(int totalFloors, int capacity) {
    Elevator* elevator = malloc(sizeof(Elevator));
    elevator->currentFloor = 0;
    elevator->totalFloors = totalFloors;
    elevator->capacity = capacity;
    elevator->currentPeople = 0;
    return elevator;
}

int enterElevator(Elevator* e, int numberOfPeople) {
    if (e->currentPeople + numberOfPeople > e->capacity) {
        return 0;
    }
    e->currentPeople += numberOfPeople;
    return 1;
}

int exitElevator(Elevator* e, int numberOfPeople) {
    if (numberOfPeople > e->currentPeople) {
        return 0;
    }
    e->currentPeople -= numberOfPeople;
    return 1;
}

int goUp(Elevator* e, int numberOfFloors) {
    if (e->currentFloor + numberOfFloors > e->totalFloors) {
        return 0;
    }
    e->currentFloor += numberOfFloors;
    return 1;
}

int goDown(Elevator* e, int numberOfFloors) {
    if (e->currentFloor - numberOfFloors < 0) {
        return 0;
    }
    e->currentFloor -= numberOfFloors;
    return 1;
}