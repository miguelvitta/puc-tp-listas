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

    return 0;
}

void togglePower(tv* t) {}

int isTvOn(tv* t) {}

int currentChannelNumber(tv* t) {}

const char* currentChannelName(tv* t) {}

void nextChannel(tv* t) {}

void previousChannel(tv* t) {}

int goToChannel(tv* t, int channelNumber) {}

void printTv(tv* t) {}
