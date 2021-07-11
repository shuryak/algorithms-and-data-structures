#include <stdio.h>

int main(void) {
    printf("Enter the count of numbers: ");
    int n;
    scanf("%d", &n);

    int count = 0; // count initialization

    int max;
    int maxIsVacant = 1; // vacancy of the first candidate for maximum

    int min;
    int minIsVacant = 1; // vacancy of the first candidate for minimum

    int sum = 0; // sum initialization

    int product = 1; // product initialization

    for (int i = 0; i < n; i++) {
        int number;
        printf("Enter number #%d: ", i + 1);
        scanf("%d", &number);

        count++;

        if (maxIsVacant) {
            max = number;
            maxIsVacant = 0;
        } else if (number > max) {
            max = number;
        }

        if (minIsVacant) {
            min = number;
            minIsVacant = 0;
        } else if (number < min) {
            min = number;
        }

        sum += number;

        product *= number;
    }

    printf("Count: %d\n", count);
    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);
    printf("Sum: %d\n", sum);
    printf("Product: %d\n", product);
}
