#include <stdio.h>
int main()
{
    int num;
    printf("Enter Two  Number:\n");
    scanf("%d", &num);
    if( num <=100 && num>=90 )
    {
        printf("Grade A");
    }
    else if( num <=89 && num>=75 )
    {
        printf("Grade B");
    }
    else if( num <=74 && num>=60 )
    {
        printf("Grade C");
    }
    else if( num <=59 && num>=50 )
    {
        printf("Grade D");
    }
    else if  ( num <=49 && num>=0 )
    {
        printf("Grade F");
    }
    return 0;
}