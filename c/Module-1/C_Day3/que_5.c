#include <stdio.h>

void findSmallestLargestDigits(int n, int numbers[]) {
    int i;
    int smallest = 0;
    int largest = 0;
    
    for (i = 0; i < n; i++) {
        int num = numbers[i];

        while (num > 0) {
            int digit = num % 10;
            
            if (digit < smallest) {
                smallest = digit;
            }
            
            if (digit > largest) {
                largest = digit;
            }

            num /= 10;
        }
    }
    
    if (n <= 0) {
        printf("Not Valid\n");
    } else {
        printf("Smallest digit: %d\n", smallest);
        printf("Largest digit: %d\n", largest);
    }
}

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n > 0) {
        int numbers[n];
        int i;

        for (i = 0; i < n; i++) {
            printf("Enter number %d: ", i + 1);
            scanf("%d", &numbers[i]);
        }

        findSmallestLargestDigits(n, numbers);
    } else {
        printf("Not Valid\n");
    }

    return 0;
}
