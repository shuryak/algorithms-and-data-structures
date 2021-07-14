#include <stdio.h>
// #include <math.h>

typedef struct {
    int *startPointer;
    int length;
} larray;

int isPrime(int number);
larray factorize(int number);

int main(void) {
    int number;
    printf("Enter any number: ");
    scanf("%d", &number);

    if (isPrime(number)) {
        printf("%d is prime number\n", number);
    } else {
        printf("%d is composite number\n", number);
    }

    printf("Multipliers of %d: ", number);
    larray multipliers = factorize(number);
    for (int i = 0; i < multipliers.length; i++) {
        printf("%d", multipliers.startPointer[i]);
        if (i != multipliers.length - 1) {
            printf(", ");
        }
    }
    printf("\n");

    free(multipliers.startPointer);

    return 0;
}

// Examples of brute-force algorithms:

int isPrime(int number) {
    for (int d = 2; d < number; d++) { // (...; d <= sqrt(number); ...)
        if (number % d == 0) {
            return 0;
        }
    }
    return 1;
}

larray factorize(int number) {
    int x = number;
    int d = 2;

    int *dividers = NULL;
    int length = 0;

    while (x != 1) {
        if (x % d == 0) {
            dividers = realloc(dividers, sizeof(int) * (length + 1));
            dividers[length] = d;
            length++;

            x /= d;
        } else {
            d++;
        }
    }

    larray result = { dividers, length };

    return result;
}
