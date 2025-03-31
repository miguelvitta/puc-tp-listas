#include <stdio.h>

#define PI 3.14159

double determineVolume(double n);

int main() {
    double radius = 0.0;

    printf("Write the value of the radius: ");
    scanf("%lf", &radius);

    double volume = determineVolume(radius);

    printf("The volume of the sphere with the radius of %.4lf is: %.4lf\n",
           radius, volume);

    return 0;
}

double determineVolume(double n) { return (4 * PI) / 3 * (n * n * n); }

