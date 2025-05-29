#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int base;
    int height;
} rectangle;

rectangle* createRectangle(int b, int h);
int calculateArea(rectangle* r);
void printRectangle(rectangle* r);
void printRectangleLimited(rectangle* r, int x);

int main() {
    printf(
        "This program does the following:\n"
        "Gets the base and height of the rectangle and creates one instance;\n"
        "Calculates the are of the rectangle;\n"
        "Prints the rectangle on the screen;\n"
        "Gets a number to use as limit and prints the rectangle up to the "
        "limit.\n\n");

    int b = 0;
    int h = 0;
    printf("Enter the base and height of the rectangle:\n");
    scanf("%d %d", &b, &h);
    rectangle* r = createRectangle(b, h);

    printf("The area of the rectangle is: %d\n", calculateArea(r));

    printRectangle(r);

    int x = 0;
    printf(
        "Enter the number that will limit the next rectangle visualization:\n");
    scanf("%d", &x);
    printRectangleLimited(r, x);

    free(r);
    return 0;
}

rectangle* createRectangle(int b, int h) {
    rectangle* r = NULL;
    r = malloc(sizeof(rectangle));
    r->base = b;
    r->height = h;
    return r;
}

int calculateArea(rectangle* r) { return r->base * r->height; }

void printRectangle(rectangle* r) {
    for (int i = 0; i < r->height; i++) {
        for (int j = 0; j < r->base; j++) {
            printf("#");
        }
        printf("\n");
    }
}

void printRectangleLimited(rectangle* r, int x) {
    int base = r->base;
    int height = r->height;

    if (base <= x) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < base; j++) {
                printf("#");
            }
            printf("\n");
        }
        return;
    }

    int limitedBase = x;
    double scaleFactor = (double)x / base;
    int scaledHeight = (int)(height * scaleFactor);

    for (int i = 0; i < scaledHeight; i++) {
        for (int j = 0; j < limitedBase; j++) {
            printf("#");
        }
        printf("\n");
    }
}