#include <stdio.h>
int main()
{
    int num1, num2;
    
    printf("Enter Two  Number:\n");
 
    scanf("%d %d", &num1, &num2);
    if(num1 > num2)
    {
        printf("%d is biggest\n", num1);
    }
    else if (num2 > num1)
    {
        printf("%d is biggest\n", num2);
    }
    else
    {
        printf("Both are Equal\n");
    }
    return 0;
}