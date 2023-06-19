#include <stdio.h>

#define SIZE 5 // Size of the array

int main() {
    int array[SIZE];
    int sum = 0;
    float average;

    printf("Enter %d elements:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &array[i]);
        sum += array[i];
    }

    average = (float)sum / SIZE;

    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);

    return 0;
}
