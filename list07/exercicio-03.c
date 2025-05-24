#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int hour;
    int minute;
    int second;
} clock;

clock* createClock();
int modifyTime(clock* r, int hour, int minute, int second);
void getTime(clock* r, int* hour, int* minute, int* second);
void advanceSecond(clock* r);
void printClock(clock* r);

int main() {
    printf(
        "This program simulates a digital clock.\n"
        "It defines a structure to store a time value (hours, minutes, and "
        "seconds),\n"
        "and allows you to:\n"
        "  1. Create a clock set to 00:00:00.\n"
        "  2. Set the clock to a specific time (validated).\n"
        "  3. Advance time by one second, repeatedly.\n"
        "  4. Display the clock's current time in HH:MM:SS format.\n\n"
        "The program will request a valid time from the user and then simulate "
        "200 seconds\n"
        "of time passage by advancing the clock and printing each new "
        "time.\n\n");

    clock* r = NULL;
    r = createClock();

    int hour = 0;
    int minute = 0;
    int second = 0;
    printf("Enter the time on the format 00:00:00\n");
    scanf("%d:%d:%d", &hour, &minute, &second);
    int sucess = modifyTime(r, hour, minute, second);
    if (sucess == 0) {
        fprintf(stderr, "Error: the time entered is invalid.\n");
        free(r);
        return 1;
    }

    getTime(r, &hour, &minute, &second);
    printf("The clock displays the time as: %02d:%02d:%02d\n", hour, minute, second);

    printf("Now let's watch the clock pass by 200 seconds.\n");

    for (int i = 0; i < 200; i++) {
        advanceSecond(r);
        printClock(r);
    }

    free(r);
    return 0;
}

clock* createClock() {
    clock* c = malloc(sizeof(clock));
    c->hour = 0;
    c->minute = 0;
    c->second = 0;
    return c;
}

int modifyTime(clock* r, int hour, int minute, int second) {
    if (hour < 0 || hour > 23) {
        return 0;
    }
    if (minute < 0 || minute > 59) {
        return 0;
    }
    if (second < 0 || second > 59) {
        return 0;
    }
    r->hour = hour;
    r->minute = minute;
    r->second = second;
    return 1;
}

void getTime(clock* r, int* hour, int* minute, int* second) {
    *hour = r->hour;
    *minute = r->minute;
    *second = r->second;
}

void advanceSecond(clock* r) {
    if (r->second == 59) {
        r->second = 0;
        if (r->minute == 59) {
            r->minute = 0;
            if (r->hour == 23) {
                r->hour = 0;
            } else {
                r->hour++;
            }
        } else {
            r->minute++;
        }
    } else {
        r->second++;
    }
}

void printClock(clock* r) {
    printf("Time: %02d:%02d:%02d\n", r->hour, r->minute, r->second);
}