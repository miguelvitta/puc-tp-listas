#include <stdio.h>

#define PI 3.14159

double determineArea(double n);

int main() {
    double radius = 0.0;

    printf("Write the value of the radius: ");
    scanf("%lf", &radius);

    double area = determineArea(radius);

    printf("The area of the circle with the radius of %.4lf is: %.4lf\n",
           radius, area);

    return 0;
}

double determineArea(double n) { return n * n * PI; }

