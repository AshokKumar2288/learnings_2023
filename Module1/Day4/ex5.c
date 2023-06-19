#include <stdio.h>

int main() {
    int arr[] = {2, 5, 9, 12, 17, 20};
    int size = sizeof(arr) / sizeof(arr[0]);

    int sumEven = 0;
    int sumOdd = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            sumEven += arr[i];
        } else {
            sumOdd += arr[i];
        }
    }

    int difference = sumEven - sumOdd;

    printf("Sum of even elements: %d\n", sumEven);
    printf("Sum of odd elements: %d\n", sumOdd);
    printf("Difference: %d\n", difference);

    return 0;
}