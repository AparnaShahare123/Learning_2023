#include <stdio.h>
#include <string.h>

int main()
{
    int roll_num;
    float per,phy,math,che,Total;
    char name[20],div[10];
    int total_subjects = 3;
    float maximum_marks = 100.0;
    printf("Enter the Roll Number :");
    scanf("%d",&roll_num);
    printf("Enter the Name :");
    scanf(" %[^\n]s",name);
    printf("Enter Physics Marks: ");
    scanf("%f", &phy);

    printf("Enter Math Marks: ");
    scanf("%f", &math);

    printf("Enter Chemistry Marks: ");
    scanf("%f", &che);

    Total = phy + math + che ;
    per = (Total / (maximum_marks * total_subjects)) * 100.0;

    // Printing the summary
    printf("-------- Summary --------\n");
    printf("Roll No: %d\n", roll_num);
    printf("Name: %s\n", name);
    printf("Physics Marks: %.2f\n", phy);
    printf("Math Marks: %.2f\n", math);
    printf("Chemistry Marks: %.2f\n", che);
    printf("Total Marks: %.2f\n", Total);
    printf("Percentage: %.2f%%\n", per);
   

    return 0;
}
   
     

