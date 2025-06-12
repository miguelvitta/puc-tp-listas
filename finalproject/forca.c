#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LENGTH 101
#define MAX_NAME_LENGTH 11
#define MAX_RANKING 3
#define DIFFICULTY_EASY 1
#define DIFFICULTY_NORMAL 2
#define DIFFICULTY_HARD 3

typedef struct {
    char name[MAX_NAME_LENGTH];
    int gameTime;
} Player;

typedef struct {
    char selectedWord[MAX_WORD_LENGTH];
    char guessedLetters[26];
    int remainingAttempts;
    int totalLetters;
} Game;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int time;
    int difficulty;
} RankEntry;

int chooseDifficulty();
char** loadWordsFromFile(const char* filename, int* wordCount);
void initGame(Game* game, char** wordList, int wordCount, int level);
void displayWordProgress(const char* selectedWord,
                         const char guessedLetters[26]);
void freeWordList(char** wordList, int wordCount);
void playGameLoop(Game* game, Player* player, struct timespec startTime,
                  int level);
void handleEndOfGame(int wonGame, Player* player, int level,
                     struct timespec startTime);
void printGameResult(int won, const char* selectedWord, const char* winMsg,
                     const char* loseMsg);
char askForGuess();
int processLetterGuess(Game* game, char guess);
int checkDiscoveredLetters(const Game* game);
int tryFullWordGuess(const char* selectedWord);
void clearInputBuffer();
void loadRanking(RankEntry ranking[], int* count);
int updateRanking(RankEntry ranking[], int* count, int level, Player* player);
void displayRanking(const RankEntry ranking[], int count, int level,
                    const Player* player, int won, int playerMadeRanking);
int compareRankEntries(const void* a, const void* b);

int main() {
    srand(time(NULL));
    struct timespec startTime;
    Player player = {0};

    printf("Enter your name (max 10 characters): ");
    scanf("%10s", player.name);
    clearInputBuffer();

    printf("Press ENTER to Start the Game!\n");
    getchar();

    clock_gettime(CLOCK_MONOTONIC, &startTime);
    int level = chooseDifficulty();

    const char* filenames[] = {"palavras-facil.txt", "palavras-normal.txt",
                               "palavras-dificil.txt"};
    const char* filename = filenames[level - 1];

    int wordCount = 0;
    char** wordList = loadWordsFromFile(filename, &wordCount);
    if (wordList == NULL) {
        return 1;
    }

    Game game = {0};
    initGame(&game, wordList, wordCount, level);
    freeWordList(wordList, wordCount);

    displayWordProgress(game.selectedWord, game.guessedLetters);
    playGameLoop(&game, &player, startTime, level);

    return 0;
}

int chooseDifficulty() {
    int option = -1;
    while (1) {
        printf(
            "\nChoose difficulty:\n1 - Easy\n2 - Normal\n3 - Hard\nOption: ");
        if (scanf("%d", &option) == 1 && option >= 1 && option <= 3) {
            clearInputBuffer();
            return option;
        }
        clearInputBuffer();
        printf("Invalid option. Please try again.\n");
    }
}

char** loadWordsFromFile(const char* filename, int* wordCount) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Failed to open word file '%s'.\n", filename);
        return NULL;
    }

    // Allocate initial memory for 10 word pointers
    int capacity = 10;
    char** words = malloc(capacity * sizeof(char*));
    if (!words) {
        fclose(file);
        return NULL;
    }

    // Read each line from the file
    int count = 0;
    char buffer[MAX_WORD_LENGTH];
    while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")] = '\0';

        // If the word array is full, expand its capacity
        if (count == capacity) {
            capacity += 10;
            char** temp = realloc(words, capacity * sizeof(char*));
            if (!temp) {
                // On failure, clean up all allocated memory
                for (int i = 0; i < count; i++) {
                    free(words[i]);
                }
                free(words);
                fclose(file);
                return NULL;
            }
            words = temp;
        }

        // Allocate memory for the new word and copy it
        words[count] = malloc(strlen(buffer) + 1);
        if (!words[count]) {
            // On failure, clean up all allocated memory
            for (int i = 0; i < count; i++) {
                free(words[i]);
            } 
            free(words);
            fclose(file);
            return NULL;
        }
        strcpy(words[count], buffer);
        count++;
    }

    // Finalize word count and close the file
    *wordCount = count;
    fclose(file);
    return words;
}

void initGame(Game* game, char** wordList, int wordCount, int level) {
    // Select a random word from the list
    int randomIndex = rand() % wordCount;
    strcpy(game->selectedWord, wordList[randomIndex]);

    // Set remaining attempts based on difficulty
    const int attempts[] = {0, 7, 5, 3};
    game->remainingAttempts = attempts[level];

    // Count the total number of letters that need to be guessed
    game->totalLetters = 0;
    for (int i = 0; game->selectedWord[i] != '\0'; i++) {
        if (isalpha(game->selectedWord[i])) {
            game->totalLetters++;
        }
    }
}

void freeWordList(char** wordList, int wordCount) {
    if (!wordList) {
        return;
    }
    for (int i = 0; i < wordCount; i++) {
        free(wordList[i]);
    }
    free(wordList);
}

void displayWordProgress(const char* selectedWord,
                         const char guessedLetters[26]) {
    printf("Word: ");
    for (size_t i = 0; selectedWord[i] != '\0'; i++) {
        char letter = toupper(selectedWord[i]);
        if (isalpha(letter)) {
            printf("%c ", guessedLetters[letter - 'A'] ? selectedWord[i] : '_');
        } else {
            printf("%c ",
                   selectedWord[i]);  // Display non-alpha characters like '-'
        }
    }
    printf("\n");
}

void printGameResult(int won, const char* selectedWord, const char* winMsg,
                     const char* loseMsg) {
    printf("\n%s: %s\n", won ? winMsg : loseMsg, selectedWord);
}

char askForGuess() {
    printf("Guess a letter or type '*' to guess the full word: ");
    int guessChar = getchar();
    clearInputBuffer();

    // Validate and process the input
    if (guessChar == EOF) {
        return 0;
    }
    if (isalpha(guessChar)) {
        return toupper(guessChar);
    }
    if (guessChar == '*') {
        return '*';
    }

    // Handle invalid input
    printf("Invalid input. Use letters or '*'.\n");
    return 0;
}

int processLetterGuess(Game* game, char guess) {
    // Check if the letter has already been guessed
    if (game->guessedLetters[guess - 'A']) {
        printf("You already guessed '%c'. Try another.\n", guess);
        return 0;  // No change in game state
    }

    // Mark the letter as guessed
    game->guessedLetters[guess - 'A'] = 1;

    // Check if the letter is in the word and update attempts if not
    if (strchr(game->selectedWord, guess) ||
        strchr(game->selectedWord, tolower(guess))) {
        printf("Good guess! '%c' is in the word.\n", guess);
    } else {
        game->remainingAttempts--;
        printf("Sorry! '%c' is not in the word. You have %d attempts left.\n",
               guess, game->remainingAttempts);
    }
    return 1;  // Game state changed
}

int checkDiscoveredLetters(const Game* game) {
    int discovered = 0;
    for (int i = 0; game->selectedWord[i] != '\0'; i++) {
        char letter = toupper(game->selectedWord[i]);
        if (isalpha(letter) && game->guessedLetters[letter - 'A']) {
            discovered++;
        }
    }
    return discovered;
}

// Prompts the user to guess the full word and checks if it's correct
int tryFullWordGuess(const char* selectedWord) {
    char attempt[MAX_WORD_LENGTH];
    printf("Full word guess: ");

    if (scanf("%s", attempt) == 1) {
        clearInputBuffer();
        size_t i = 0;
        while (selectedWord[i] != '\0' && attempt[i] != '\0') {
            if (toupper(selectedWord[i]) != toupper(attempt[i])) {
                return 0;
            }
            i++;
        }
        return (selectedWord[i] == '\0' && attempt[i] == '\0');
    }

    clearInputBuffer();
    return 0;
}

void clearInputBuffer() {
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void loadRanking(RankEntry ranking[], int* count) {
    FILE* file = fopen("ranking.bin", "rb");
    if (!file) {
        *count = 0;
        return;
    }
    *count = fread(ranking, sizeof(RankEntry), MAX_RANKING * 3, file);
    fclose(file);
}

// A comparison function for qsort to sort RankEntry structs
int compareRankEntries(const void* a, const void* b) {
    const RankEntry* entryA = (const RankEntry*)a;
    const RankEntry* entryB = (const RankEntry*)b;

    // Primary sort key: difficulty level
    if (entryA->difficulty != entryB->difficulty) {
        return entryA->difficulty - entryB->difficulty;
    }

    // Secondary sort key: time
    return entryA->time - entryB->time;
}

int updateRanking(RankEntry ranking[], int* count, int level, Player* player) {
    // Do not update if the game was not won
    if (player->gameTime == 0) {
        return 0;
    }

    // Find stats (count, slowest time) for the current difficulty level
    int levelCount = 0;
    int slowestTime = -1;
    int slowestIdx = -1;
    for (int i = 0; i < *count; i++) {
        if (ranking[i].difficulty == level) {
            levelCount++;
            if (ranking[i].time > slowestTime) {
                slowestTime = ranking[i].time;
                slowestIdx = i;
            }
        }
    }

    // Check if the player's score is good enough to make the list
    if (levelCount == MAX_RANKING && player->gameTime >= slowestTime) {
        return 0;  // Score is not fast enough to replace the slowest player
    }

    // Add the new score or replace the slowest one
    if (levelCount < MAX_RANKING) {
        // There is space, so add the new player to the end of the array
        ranking[*count].difficulty = level;
        ranking[*count].time = player->gameTime;
        strcpy(ranking[*count].name, player->name);
        (*count)++;
    } else {
        // No space, so replace the slowest player for this level
        ranking[slowestIdx].time = player->gameTime;
        strcpy(ranking[slowestIdx].name, player->name);
    }

    // Sort the entire ranking array to maintain order
    qsort(ranking, *count, sizeof(RankEntry), compareRankEntries);

    // ave the updated ranking back to the file
    FILE* file = fopen("ranking.bin", "wb");
    if (file) {
        fwrite(ranking, sizeof(RankEntry), *count, file);
        fclose(file);
    }

    // If we are here, the player's score was successfully added.
    return 1;
}

void displayRanking(const RankEntry ranking[], int count, int level,
                    const Player* player, int won, int playerMadeRanking) {
    // Don't display anything if there's no ranking and the player didn't win
    if (count == 0 && !won) {
        return;
    }

    // Print the ranking header
    const char* levelNames[] = {NULL, "Easy", "Normal", "Hard"};
    printf("\n--- Ranking for %s level ---\n", levelNames[level]);

    // Iterate through the list and print scores for the current level
    int displayed = 0;
    for (int i = 0; i < count; i++) {
        if (ranking[i].difficulty == level) {
            printf("%d. %-10s - %d seconds\n", displayed + 1, ranking[i].name,
                   ranking[i].time);
            displayed++;
        }
    }

    // Show a message if no scores exist for this level
    if (displayed == 0) {
        printf("No scores yet for this level.\n");
    }

    // If the player won but didn't make the top N, show their score separately
    if (won && !playerMadeRanking) {
        printf("Your score: %-10s - %d seconds (not in the top %d)\n",
               player->name, player->gameTime, MAX_RANKING);
    }
}

void playGameLoop(Game* game, Player* player, struct timespec startTime,
                  int level) {
    int wonGame = 0;
    int gameIsOver = 0;

    // Loop continues as long as there are attempts left and the game isn't over
    while (game->remainingAttempts > 0 && !gameIsOver) {
        printf("\nAttempts left: %d\n", game->remainingAttempts);
        displayWordProgress(game->selectedWord, game->guessedLetters);

        // Get and process the player's guess
        char guess = askForGuess();
        if (guess != 0) {  // A valid guess was made
            if (guess == '*') {
                // Player wants to guess the full word
                wonGame = tryFullWordGuess(game->selectedWord);
                gameIsOver = 1;
                printGameResult(wonGame, game->selectedWord, "Congratulations!",
                                "Wrong guess! The word was");
            } else if (processLetterGuess(game, guess)) {
                // Player guessed a letter, check if the word is now complete
                if (checkDiscoveredLetters(game) == game->totalLetters) {
                    wonGame = 1;
                    gameIsOver = 1;
                    printGameResult(wonGame, game->selectedWord,
                                    "Congratulations!", "");
                }
            }
        }
    }

    // Handle the case where the player runs out of attempts
    if (!wonGame && !gameIsOver) {
        printf("\nNo more attempts. You must now guess the word.\n");
        wonGame = tryFullWordGuess(game->selectedWord);
        printGameResult(wonGame, game->selectedWord, "Correct!",
                        "Incorrect! The word was");
    }
    handleEndOfGame(wonGame, player, level, startTime);
}

// All endgame logic, calculating time and updating the ranking
void handleEndOfGame(int wonGame, Player* player, int level,
                     struct timespec startTime) {
    // If the player won, calculate their total game time
    if (wonGame) {
        struct timespec endTime;
        clock_gettime(CLOCK_MONOTONIC, &endTime);
        player->gameTime = (int)(endTime.tv_sec - startTime.tv_sec);
        printf("Game duration: %d seconds.\n", player->gameTime);
    }

    // Load the current ranking from the file
    RankEntry ranking[MAX_RANKING * 3];
    int rankCount = 0;
    loadRanking(ranking, &rankCount);

    // If the player won, try to update the ranking with their score
    int playerMadeRanking = 0;
    if (wonGame) {
        playerMadeRanking = updateRanking(ranking, &rankCount, level, player);
    }

    displayRanking(ranking, rankCount, level, player, wonGame,
                   playerMadeRanking);
}
