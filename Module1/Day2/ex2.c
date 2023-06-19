#include <stdio.h>

void swap(void* a, void* b, size_t size) {
    char* p = (char*)a;
    char* q = (char*)b;

    for (size_t i = 0; i < size; i++) {
        char temp = *(p + i);
        *(p + i) = *(q + i);
        *(q + i) = temp;
    }
}

int main() {
    int num1 = 10, num2 = 20;
    printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);

    swap(&num1, &num2, sizeof(int));

    printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);

    double pi = 3.14159, e = 2.71828;
    printf("Before swapping: pi = %lf, e = %lf\n", pi, e);

    swap(&pi, &e, sizeof(double));

    printf("After swapping: pi = %lf, e = %lf\n", pi, e);

    return 0;
}
