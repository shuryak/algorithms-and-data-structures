#include <stdio.h>

int getCount(int *array_start, int *arrayEnd);
int getMax(int *array, int count);
int getMin(int *array, int count);
int getSum(int *array, int count);
int getProduct(int *array, int count);

int main(void) {
    int array[] = { 17, 103, 32, 98, 77 };

    // int count = sizeof(array) / sizeof(array[0]);
    int count = getCount(array, array + (sizeof(array) / sizeof(array[0])));
    int max = getMax(array, count);
    int min = getMin(array, count);
    int sum = getSum(array, count);
    int product = getProduct(array, count);

    printf("Count: %d\n", count);
    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);
    printf("Sum: %d\n", sum);
    printf("Product: %d\n", product);

    return 0;
}

int getCount(int *arrayStart, int *arrayEnd) {
    int count = 0; // count initialization

    for (int *c = arrayStart; c < arrayEnd; c++) {
        count++;
    }
    
    return count;
}

int getMax(int *array, int count) {
    int max;
    int maxIsVacant = 1; // vacancy of the first candidate for maximum

    for (int *c = array; c < array + count; c++) {
        if (maxIsVacant) {
            max = *c;
            maxIsVacant = 0;
        } else if (*c > max) {
            max = *c;
        }
    }

    return max;
}

int getMin(int *array, int count) {
    int min;
    int minIsVacant = 1; // vacancy of the first candidate for minimum

    for (int *c = array; c < array + count; c++) {
        if (minIsVacant) {
            min = *c;
            minIsVacant = 0;
        } else if (*c < min) {
            min = *c;
        }
    }

    return min;
}

int getSum(int *array, int count) {
    int sum = 0; // sum initialization

    for (int *c = array; c < array + count; c++) {
        sum += *c;
    }

    return sum;
}

int getProduct(int *array, int count) {
    int product = 1; // product initialization

    for (int *c = array; c < array + count; c++) {
        product *= *c;
    }

    return product;
}
