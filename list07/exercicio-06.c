#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a small epsilon for floating-point comparisons
#define EPSILON 1e-4

typedef struct {
    double x;
    double y;
} point;

typedef struct {
    point a;
    point b;
    point c;
} triangle;

point* createPoint(double x, double y);
triangle* createTriangle(point* a, point* b, point* c);
int determineTriangleType(triangle* t);

int main() {
    printf(
        "This program does the following:\n"
        "Creates a struct named point with two coordinates;\n"
        "Creates a triangle with three points.\n"
        "Classifies the triangle accordingly to it's type.\n\n");

    double x = 0;
    double y = 0;
    printf("Enter the coordinates for point A:\n");
    scanf("%lf %lf", &x, &y);
    point* a = createPoint(x, y);

    printf("Enter the coordinates for point B:\n");
    scanf("%lf %lf", &x, &y);
    point* b = createPoint(x, y);

    printf("Enter the coordinates for point C:\n");
    scanf("%lf %lf", &x, &y);
    point* c = createPoint(x, y);

    triangle* t = createTriangle(a, b, c);

    int result = determineTriangleType(t);
    char type[50];
    switch (result) {
        case 1:
            strcpy(type, "equilateral");
            break;
        case 2:
            strcpy(type, "isosceles");
            break;
        case 3:
            strcpy(type, "scalene");
            break;
        default:
            strcpy(type, "invalid. These points don't form a triangle");
    }
    printf("The triangle is: %s\n", type);

    free(a);
    free(b);
    free(c);
    free(t);
    return 0;
}

point* createPoint(double x, double y) {
    point* p = NULL;
    p = malloc(sizeof(point));
    p->x = x;
    p->y = y;
    return p;
}

triangle* createTriangle(point* a, point* b, point* c) {
    triangle* t = NULL;
    t = malloc(sizeof(triangle));
    t->a = *a;
    t->b = *b;
    t->c = *c;
    return t;
}

double calculateAB(triangle* t) {
    double differenceX = t->b.x - t->a.x;
    double differenceY = t->b.y - t->a.y;
    return sqrt(differenceX * differenceX + differenceY * differenceY);
}

double calculateAC(triangle* t) {
    double differenceX = t->c.x - t->a.x;
    double differenceY = t->c.y - t->a.y;
    return sqrt(differenceX * differenceX + differenceY * differenceY);
}

double calculateBC(triangle* t) {
    double differenceX = t->c.x - t->b.x;
    double differenceY = t->c.y - t->b.y;
    return sqrt(differenceX * differenceX + differenceY * differenceY);
}

int determineTriangleType(triangle* t) {
    if ((fabs(t->a.x - t->b.x) < EPSILON && fabs(t->a.y - t->b.y) < EPSILON) ||
        (fabs(t->a.x - t->c.x) < EPSILON && fabs(t->a.y - t->c.y) < EPSILON) ||
        (fabs(t->b.x - t->c.x) < EPSILON && fabs(t->b.y - t->c.y) < EPSILON)) {
        return -1;  // check for equal points, not a triangle
    }
    double sideAB = calculateAB(t);
    double sideAC = calculateAC(t);
    double sideBC = calculateBC(t);

    if ((sideAB + sideAC <= sideBC) || (sideAB + sideBC <= sideAC) ||
        (sideAC + sideBC <= sideAB)) {
        return -1;  // Not a triangle
    }
    // Equilateral: all sides equal
    if (fabs(sideAB - sideAC) < EPSILON && fabs(sideAC - sideBC) < EPSILON && fabs(sideAB - sideBC) < EPSILON) {
        return 1;
    }
    // Isosceles: any two sides equal
    if (fabs(sideAB - sideAC) < EPSILON || fabs(sideAB - sideBC) < EPSILON || fabs(sideAC - sideBC) < EPSILON) {
        return 2;
    }
    // Scalene: all sides different
    return 3;
}