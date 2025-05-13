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

    complexNumber* sum = NULL;
    sum = addComplexNumber(x, y);
    printf("The sum of X and Y is: ");
    printComplexNumber(sum);

    complexNumber* subtraction = NULL;
    subtraction = subtractComplexNumber(x, y);
    printf("The subtraction of X and Y is: ");
    printComplexNumber(subtraction);

    complexNumber* multiplication = NULL;
    multiplication = multiplyComplexNumber(x, y);
    printf("The multiplication of X and Y is: ");
    printComplexNumber(multiplication);

    complexNumber* division = NULL;
    division = divideComplexNumber(x, y);
    printf("The division of X and Y is: ");
    printComplexNumber(division);

    complexNumber* sumXA = NULL;
    sumXA = addComplexReal(x, a);
    printf("The sum of X and A is: ");
    printComplexNumber(sumXA);

    complexNumber* subtractionXA = NULL;
    subtractionXA = subtractComplexReal(x, a);
    printf("The subtraction of X and A is: ");
    printComplexNumber(subtractionXA);

    complexNumber* multiplyXA = NULL;
    multiplyXA = multiplyComplexReal(x, a);
    printf("The multiplication of X and A is: ");
    printComplexNumber(multiplyXA);

    complexNumber* divisionXA = NULL;
    divisionXA = divideComplexReal(x, a);
    printf("The division of X and A is: ");
    printComplexNumber(divisionXA);

    complexNumber* sumAY = NULL;
    sumAY = addRealComplex(a, y);
    printf("The sum of A and Y is: ");
    printComplexNumber(sumAY);

    complexNumber* subtractionAY = NULL;
    subtractionAY = subtractRealComplex(a, y);
    printf("The subtraction of A and Y is: ");
    printComplexNumber(subtractionAY);

    complexNumber* multiplyAY = NULL;
    multiplyAY = multiplyRealComplex(a, y);
    printf("The multiplication of A and Y is: ");
    printComplexNumber(multiplyAY);

    complexNumber* divisionAY = NULL;
    divisionAY = divideRealComplex(a, y);
    printf("The division of A and Y is: ");
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
    complexNumber* number = (complexNumber*)malloc(sizeof(complexNumber));
    number->real = real;
    number->imaginary = imaginary;
    return number;
}

void printComplexNumber(complexNumber* number) {
    if (number->imaginary == 0) {
        printf("%.2lf\n", number->real);
    } else {
        if (number->real == 0) {
            printf("%.2lf\n", number->imaginary);
        } else {
            printf("%.2lf + %.2lfi\n", number->real, number->imaginary);
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
    return createComplexNumber(x->real * y->real, x->imaginary * y->imaginary);
}

complexNumber* divideComplexNumber(complexNumber* x, complexNumber* y) {
    return createComplexNumber(x->real / y->real, x->imaginary / y->imaginary);
}

complexNumber* addComplexReal(complexNumber* x, double a) {
    return createComplexNumber(x->real + a, x->imaginary + a);
}

complexNumber* subtractComplexReal(complexNumber* x, double a) {
    return createComplexNumber(x->real - a, x->imaginary - a);
}

complexNumber* multiplyComplexReal(complexNumber* x, double a) {
    return createComplexNumber(x->real * a, x->imaginary * a);
}

complexNumber* divideComplexReal(complexNumber* x, double a) {
    return createComplexNumber(x->real / a, x->imaginary / a);
}

complexNumber* addRealComplex(double a, complexNumber* y) {
    return createComplexNumber(a + y->real, a + y->imaginary);
}

complexNumber* subtractRealComplex(double a, complexNumber* y) {
    return createComplexNumber(a - y->real, a - y->imaginary);
}

complexNumber* multiplyRealComplex(double a, complexNumber* y) {
    return createComplexNumber(a * y->real, a * y->imaginary);
}

complexNumber* divideRealComplex(double a, complexNumber* y) {
    return createComplexNumber(a / y->real, a / y->imaginary);
}