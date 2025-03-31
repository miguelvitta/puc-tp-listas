#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 300

void checkPerfectNumber(int* divisors, int n);
void quickSort(int* divisors, int left, int right);
int partition(int* divisors, int left, int right);
void printPerfectNumber(int* divisors, int n, int j);

int main() {
    for (int i = 1; i <= 10000; i++) {
        int* divisors = NULL;
        divisors = (int*)malloc(sizeof(int) * SIZE);
        if (divisors == NULL) {
            fprintf(stderr, "\nMemory allocation has failed\n");
            return 1;
        }
        checkPerfectNumber(divisors, i);
        free(divisors);
    }

    return 0;
}

void checkPerfectNumber(int* divisors, int n) {
    if (n <= 1) {
        return;
    }

    int rad = (int)sqrt(n);
    int sum = 1;
    int j = 1;
    divisors[0] = 1;

    for (int i = 2; i <= rad && sum <= n; i++) {
        if (n % i == 0) {
            sum += i;
            divisors[j++] = i;
            if (i != n / i) {
                sum += n / i;
                divisors[j++] = n / i;
            }
        }
    }
    if (sum == n) {
        quickSort(divisors, 0, j - 1);
        printPerfectNumber(divisors, n, j);
    }
}

void quickSort(int* divisors, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(divisors, left, right);
        quickSort(divisors, left, pivotIndex - 1);
        quickSort(divisors, pivotIndex + 1, right);
    }
}

int partition(int* divisors, int left, int right) {
    int pivot = divisors[right];
    int j = left - 1;
    for (int i = left; i < right; i++) {
        if (divisors[i] < pivot) {
            j++;
            int aux = divisors[j];
            divisors[j] = divisors[i];
            divisors[i] = aux;
        }
    }
    int aux = divisors[j + 1];
    divisors[j + 1] = divisors[right];
    divisors[right] = aux;
    return j + 1;
}

void printPerfectNumber(int* divisors, int n, int j) {
    printf("%d =", n);
    for (int i = 0; i < j; i++) {
        if (i > 0) {
            printf(" +");
        }
        printf(" %d", divisors[i]);
    }
    printf("\n");
}

