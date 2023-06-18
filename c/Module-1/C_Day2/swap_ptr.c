#include <stdio.h>
void swap(void* a, void* b, size_t size) {
    char* p1 = (char*)a;
    char* p2 = (char*)b;
    char temp;

    for (size_t i = 0; i < size; i++) {
        temp = *(p1 + i);
        *(p1 + i) = *(p2 + i);
        *(p2 + i) = temp;
    }
}

int main() {
    int num1 , num2 ;
    printf("Enter value:");
    scanf("%d %d",&num1,&num2);
    printf("Before swap: num1 = %d, num2 = %d\n", num1, num2);
    swap(&num1, &num2, sizeof(int));
    printf("After swap: num1 = %d, num2 = %d\n", num1, num2);
    printf("--------------------************-----------------------\n");

    float float1 , float2;
    printf("Enter Float value:");
    scanf("%f %f",&float1,&float2);
    printf("Before swap: float1 = %.2f, float2 = %.2f\n", float1, float2);
    swap(&float1, &float2, sizeof(float));
    printf("After swap: float1 = %.2f, float2 = %.2f\n", float1, float2);
    printf("--------------------************-----------------------\n");

    char char1, char2;
    printf("Enter character value:");
    scanf("%s %s",&char1,&char2);
    printf("Before swap: char1 = %c, char2 = %c\n", char1, char2);
    swap(&char1, &char2, sizeof(char));
    printf("After swap: char1 = %c, char2 = %c\n", char1, char2);
    printf("--------------------************-----------------------\n");
    return 0;
}