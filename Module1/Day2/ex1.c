#include <stdio.h>

int main() {
    double x = 0.7;
    unsigned long long *ptr = (unsigned long long *)&x; // Pointer to treat x as unsigned long long

    unsigned long long exponent = (*ptr & 0x7FF0000000000000) >> 52; // Extracting exponent bits

    printf("Exponent in hexadecimal: 0x%llX\n", exponent);
    
    printf("Exponent in binary: 0b");
    for (int i = 11; i >= 0; i--) {
        unsigned long long bit = (exponent >> i) & 1;
        printf("%llu", bit);
    }
    printf("\n");

    return 0;
}
