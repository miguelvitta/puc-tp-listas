#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double real;
    double imaginary;
} complexNumber;

complexNumber* createComplexNumber(double real, double imaginary);
void printComplexNumber(complexNumber* number);
complexNumber* addComplexNumber(complexNumber* x, complexNumber* y);
complexNumber* subtractComplexNumber(complexNumber* x, complexNumber* y);
complexNumber* multiplyComplexNumber(complexNumber* x, complexNumber* y);
complexNumber* divideComplexNumber(complexNumber* x, complexNumber* y);
complexNumber* addComplexReal(complexNumber* x, double a);
complexNumber* subtractComplexReal(complexNumber* x, double a);
complexNumber* multiplyComplexReal(complexNumber* x, double a);
complexNumber* divideComplexReal(complexNumber* x, double a);
complexNumber* addRealComplex(double a, complexNumber* y);
complexNumber* subtractRealComplex(double a, complexNumber* y);
complexNumber* multiplyRealComplex(double a, complexNumber* y);
complexNumber* divideRealComplex(double a, complexNumber* y);

int main() {
    printf(
        "This program performs operations with complex numbers:\n"
        "  1. Defines a struct to represent complex numbers with real and "
        "imaginary parts.\n"
        "  2. Creates two complex numbers from user input (real and imaginary "
        "parts).\n"
        "  3. Reads a real number from the user.\n"
        "  4. Performs and prints results of the following operations:\n"
        "     - Addition, subtraction, multiplication, and division between "
        "two complex numbers (X and Y).\n"
        "     - Operations between a complex number and a real number (X and "
        "A).\n"
        "     - Operations between a real number and a complex number (A and "
        "Y).\n"
        "  5. Prints all complex numbers in the standard form A + Bi.\n");

    double real1 = 0.0;
    printf("Enter the real part of the first complex number:\n");
    scanf("%lf", &real1);

    printf("Enter the imaginary part of the first complex number:\n");
    double imaginary1 = 0.0;
    scanf("%lf", &imaginary1);

    complexNumber* x = NULL;
    x = createComplexNumber(real1, imaginary1);

    double real2 = 0.0;
    printf("Enter the real part of the second complex number:\n");
    scanf("%lf", &real2);

    printf("Enter the imaginary part of the second complex number:\n");
    double imaginary2 = 0.0;
    scanf("%lf", &imaginary2);

    complexNumber* y = NULL;
    y = createComplexNumber(real2, imaginary2);

    double a = 0;
    printf("Now enter the number a, that will be used in some operations:\n");
    scanf("%lf", &a);

    printf("x = ");
    printComplexNumber(x);
    printf("y = ");
    printComplexNumber(y);

    complexNumber* sum = addComplexNumber(x, y);
    printf("X + Y = ");
    printComplexNumber(sum);

    complexNumber* subtraction = subtractComplexNumber(x, y);
    printf("X - Y = ");
    printComplexNumber(subtraction);

    complexNumber* multiplication = multiplyComplexNumber(x, y);
    printf("X * Y = ");
    printComplexNumber(multiplication);

    complexNumber* division = divideComplexNumber(x, y);
    printf("X / Y = ");
    printComplexNumber(division);

    complexNumber* sumXA = addComplexReal(x, a);
    printf("X + A = ");
    printComplexNumber(sumXA);

    complexNumber* subtractionXA = subtractComplexReal(x, a);
    printf("X - A = ");
    printComplexNumber(subtractionXA);

    complexNumber* multiplyXA = multiplyComplexReal(x, a);
    printf("X * A = ");
    printComplexNumber(multiplyXA);

    complexNumber* divisionXA = divideComplexReal(x, a);
    printf("X / A = ");
    printComplexNumber(divisionXA);

    complexNumber* sumAY = addRealComplex(a, y);
    printf("A + Y = ");
    printComplexNumber(sumAY);

    complexNumber* subtractionAY = subtractRealComplex(a, y);
    printf("A - Y = ");
    printComplexNumber(subtractionAY);

    complexNumber* multiplyAY = multiplyRealComplex(a, y);
    printf("A * Y = ");
    printComplexNumber(multiplyAY);

    complexNumber* divisionAY = divideRealComplex(a, y);
    printf("A / Y = ");
    printComplexNumber(divisionAY);

    free(x);
    free(y);
    free(sum);
    free(subtraction);
    free(multiplication);
    free(division);
    free(sumXA);
    free(subtractionXA);
    free(multiplyXA);
    free(divisionXA);
    free(sumAY);
    free(subtractionAY);
    free(multiplyAY);
    free(divisionAY);

    return 0;
}

complexNumber* createComplexNumber(double real, double imaginary) {
    complexNumber* number = malloc(sizeof(complexNumber));
    number->real = real;
    number->imaginary = imaginary;
    return number;
}

void printComplexNumber(complexNumber* number) {
    if (number == NULL) {
        printf("Undefined (possible division by zero)\n");
        return;
    }

    if (number->imaginary == 0) {
        printf("%.2lf\n", number->real);
    } else {
        if (number->real == 0) {
            printf("%.2lfi\n", number->imaginary);
        } else {
            if (number->imaginary < 0) {
                printf("%.2lf - %.2lfi\n", number->real, -number->imaginary);
            } else {
                printf("%.2lf + %.2lfi\n", number->real, number->imaginary);
            }
        }
    }
}

complexNumber* addComplexNumber(complexNumber* x, complexNumber* y) {
    return createComplexNumber(x->real + y->real, x->imaginary + y->imaginary);
}

complexNumber* subtractComplexNumber(complexNumber* x, complexNumber* y) {
    return createComplexNumber(x->real - y->real, x->imaginary - y->imaginary);
}

complexNumber* multiplyComplexNumber(complexNumber* x, complexNumber* y) {
    double real = x->real * y->real - x->imaginary * y->imaginary;
    double imaginary = x->real * y->imaginary + x->imaginary * y->real;
    return createComplexNumber(real, imaginary);
}

complexNumber* divideComplexNumber(complexNumber* x, complexNumber* y) {
    double denominator = y->real * y->real + y->imaginary * y->imaginary;
    if (denominator == 0) {
        return NULL;
    }

    double real =
        (x->real * y->real + x->imaginary * y->imaginary) / denominator;
    double imaginary =
        (x->imaginary * y->real - x->real * y->imaginary) / denominator;
    return createComplexNumber(real, imaginary);
}

complexNumber* addComplexReal(complexNumber* x, double a) {
    return createComplexNumber(x->real + a, x->imaginary);
}

complexNumber* subtractComplexReal(complexNumber* x, double a) {
    return createComplexNumber(x->real - a, x->imaginary);
}

complexNumber* multiplyComplexReal(complexNumber* x, double a) {
    return createComplexNumber(x->real * a, x->imaginary * a);
}

complexNumber* divideComplexReal(complexNumber* x, double a) {
    if (a == 0) {
        return NULL;
    }
    return createComplexNumber(x->real / a, x->imaginary / a);
}

complexNumber* addRealComplex(double a, complexNumber* y) {
    return createComplexNumber(a + y->real, y->imaginary);
}

complexNumber* subtractRealComplex(double a, complexNumber* y) {
    return createComplexNumber(a - y->real, -y->imaginary);
}

complexNumber* multiplyRealComplex(double a, complexNumber* y) {
    return createComplexNumber(a * y->real, a * y->imaginary);
}

complexNumber* divideRealComplex(double a, complexNumber* y) {
    double denom = y->real * y->real + y->imaginary * y->imaginary;
    if (denom == 0) {
        return NULL;
    }

    double real = (a * y->real) / denom;
    double imaginary = (-a * y->imaginary) / denom;
    return createComplexNumber(real, imaginary);
}