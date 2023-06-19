#include <stdio.h>

int countSetBits(int num) {
    int count = 0;
    while (num != 0) {
        count += num & 1;   // Check the least significant bit
        num >>= 1;         // Right shift to consider the next bit
    }
    return count;
}

int main() {
    int array[] = {0x1, 0xF4, 0x10001};
    int length = sizeof(array) / sizeof(array[0]);

    int totalSetBits = 0;
    for (int i = 0; i < length; i++) {
        totalSetBits += countSetBits(array[i]);
    }

    printf("Total number of set bits: %d\n", totalSetBits);

    return 0;
}
