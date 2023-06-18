#include <stdio.h>

int main() 
{
    int a[] = {11,22,33,44,55,66,77,88,99};
    int size = sizeof(a) / sizeof(a[0]);
    int sum = 0;

    for (int i = 0; i < size; i += 2)
    {
        sum += a[i];
    }

    printf("Sum of Alternate elements in Array: %d\n", sum);

    return 0;
}