#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int channelNumber;
    char channelName[100];
} canalTv;

typedef struct {
    int status;  // 1 = on, 0 = off
    int totalChannels;
    int currentChannelNumber;
    canalTv canais[5];
} tv;

void togglePower(tv* t);
int isTvOn(tv* t);
int currentChannelNumber(tv* t);
const char* currentChannelName(tv* t);
void nextChannel(tv* t);
void previousChannel(tv* t);
int goToChannel(tv* t, int channelNumber);
void printTv(tv* t);

int main() {
    printf(
        "This program simulates a digital television with multiple channels.\n"
        "It defines two structures:\n"
        "  - 'canalTv' to store the number and name of a TV channel.\n"
        "  - 'tv' to represent a TV object, which tracks whether it's on or "
        "off,\n"
        "    how many channels it has, which channel is currently selected,\n"
        "    and stores a fixed list of available channels.\n\n"
        "The program allows you to:\n"
        "  1. Turn the TV on or off.\n"
        "  2. Check if the TV is currently turned on.\n"
        "  3. Get the number of the currently selected channel.\n"
        "  4. Get the name of the currently selected channel,\n"
        "     showing 'Sem sinal' if the selected number doesn't match any "
        "known channel,\n"
        "     or 'TV está desligada' if the TV is off.\n"
        "  5. Advance to the next channel by number among existing channels,\n"
        "     wrapping around when reaching the end.\n"
        "  6. Go back to the previous channel number among existing channels,\n"
        "     wrapping around when reaching the beginning.\n"
        "  7. Go directly to a specific channel number (valid or not),\n"
        "     reporting whether it exists among known channels.\n"
        "  8. Print the TV's current status and channel information,\n"
        "     indicating if the channel has no signal or if the TV is off.\n\n"
        "The program will present an interactive menu for the user to perform "
        "these\n"
        "operations in a loop, until an exit option is selected.\n\n");

    tv* t = NULL;
    t = malloc(sizeof(tv));
    if (t == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    t->status = 0;
    t->totalChannels = 5;
    t->currentChannelNumber = 1;
    t->canais[0] = (canalTv){1, "Globo"};
    t->canais[1] = (canalTv){3, "Record"};
    t->canais[2] = (canalTv){5, "SBT"};
    t->canais[3] = (canalTv){7, "Rede TV"};
    t->canais[4] = (canalTv){9, "TV Cultura"};

    int option = 0;
    int channelInput = 0;

    do {
        printf("\n====== TV Menu ======\n");
        printf("1. Turn TV ON/OFF\n");
        printf("2. Check if TV is ON\n");
        printf("3. Show current channel number\n");
        printf("4. Show current channel name\n");
        printf("5. Next channel\n");
        printf("6. Previous channel\n");
        printf("7. Go to a specific channel\n");
        printf("8. Print TV status\n");
        printf("0. Exit\n");
        printf("======================\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                togglePower(t);
                printf("TV is now %s.\n", isTvOn(t) ? "ON" : "OFF");
                break;
            case 2:
                printf("TV is %s.\n", isTvOn(t) ? "ON" : "OFF");
                break;
            case 3:
                if (isTvOn(t)) {
                    printf("Current channel number: %d\n",
                           currentChannelNumber(t));
                } else {
                    printf("TV is off.\n");
                }
                break;
            case 4:
                printf("Current channel name: %s\n", currentChannelName(t));
                break;
            case 5:
                nextChannel(t);
                printf("Switched to next channel: %d - %s\n",
                       currentChannelNumber(t), currentChannelName(t));
                break;
            case 6:
                previousChannel(t);
                printf("Switched to previous channel: %d - %s\n",
                       currentChannelNumber(t), currentChannelName(t));
                break;
            case 7:
                printf("Enter the channel number to go to: ");
                scanf("%d", &channelInput);
                if (goToChannel(t, channelInput) != 0) {
                    printf("Switched to channel: %d - %s\n",
                           currentChannelNumber(t), currentChannelName(t));
                } else {
                    printf("Channel %d not found. No signal.\n", channelInput);
                }
                break;
            case 8:
                printTv(t);
                break;
            case 0:
                printf("Exiting TV simulation. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 0);

    free(t);
    return 0;
}

void togglePower(tv* t) { t->status = t->status == 1 ? 0 : 1; }

int isTvOn(tv* t) { return t->status; }

int currentChannelNumber(tv* t) {
    if (t->status == 1) {
        return t->currentChannelNumber;
    }
    return -1;
}

const char* currentChannelName(tv* t) {
    if (t->status == 1) {
        for (int i = 0; i < t->totalChannels; i++) {
            if (t->currentChannelNumber == t->canais[i].channelNumber) {
                return t->canais[i].channelName;
            }
        }
        return "No signal.\n";
    }
    return "TV is off.\n";
}

void nextChannel(tv* t) {
    if (t->status != 1) {
        return;
    }
    for (int i = 0; i < t->totalChannels; i++) {
        if (t->canais[i].channelNumber > t->currentChannelNumber) {
            t->currentChannelNumber = t->canais[i].channelNumber;
            return;
        }
    }
    t->currentChannelNumber = t->canais[0].channelNumber;
}

void previousChannel(tv* t) {
    if (t->status != 1) {
        return;
    }
    for (int i = t->totalChannels - 1; i >= 0; i--) {
        if (t->canais[i].channelNumber < t->currentChannelNumber) {
            t->currentChannelNumber = t->canais[i].channelNumber;
            return;
        }
    }
    t->currentChannelNumber = t->canais[t->totalChannels - 1].channelNumber;
}

int goToChannel(tv* t, int channelNumber) {
    if (t->status == 1) {
        t->currentChannelNumber = channelNumber;
        for (int i = 0; i < t->totalChannels; i++) {
            if (t->canais[i].channelNumber == t->currentChannelNumber) {
                return 1;
            }
        }
        return 0;
    }
    return 0;
}

void printTv(tv* t) {
    if (t->status == 1) {
        for (int i = 0; i < t->totalChannels; i++) {
            if (t->canais[i].channelNumber == t->currentChannelNumber) {
                printf("%d - %s\n", t->canais[i].channelNumber,
                       t->canais[i].channelName);
                return;
            }
        }
        printf("No signal.\n");
        return;
    }
    printf("TV is off.\n");
}
