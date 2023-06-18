#include <stdio.h>

int deleteDigit(int num) {
    int largest = 0;
    int pow10 = 1;

    while (pow10 <= num) {
        int temp = (num / (pow10 * 10)) * pow10 + (num % pow10);
        if (temp > largest) {
            largest = temp;
        }
        pow10 *= 10;
    }

    return largest;
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    int largestNumber = deleteDigit(num);

    printf("Largest number after deleting a single digit: %d\n", largestNumber);

    return 0;
}
