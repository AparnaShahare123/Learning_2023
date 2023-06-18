#include <stdio.h>

void printExponent(double num) {
    unsigned long long* p = (unsigned long long*)&num;
    unsigned long long exponent = (*p & 0x7FF0000000000000) >> 52;
    
    printf("Exponent (hex): 0x%llX\n", exponent);
    
    printf("Exponent (binary): ");
    for (int i = 11; i >= 0; i--) {
        printf("%d", (exponent >> i) & 1);
    }
    printf("\n");
}

int main() {
    double x = 0.7;
    
    printExponent(x);
    
    return 0;
}
