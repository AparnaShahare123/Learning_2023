#include <stdio.h>

// Function to count the number of set bits in a value
int countSetBits(unsigned int value) {
    int count = 0;

    while (value > 0) {
        count += value & 1;
        value >>= 1;
    }

    return count;
}

int main() {
    unsigned int a[] = {0x1, 0xF4, 0x10001};
    int size = sizeof(a) / sizeof(a[0]);
    int totalSetBits = 0;

    for (int i = 0; i < size; i++) {
        totalSetBits += countSetBits(a[i]);
    }

    printf("Total number of set bits: %d\n", totalSetBits);

    return 0;
}
