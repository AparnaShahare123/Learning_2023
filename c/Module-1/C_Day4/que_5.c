#include <stdio.h>
#include <string.h>

struct Student {
    int rollNumber;
    char name[50];
};

void swapFields(struct Student *s1, struct Student *s2) {
    int tempRollNumber;
    char tempName[50];

    // Swap roll numbers
    tempRollNumber = s1->rollNumber;
    s1->rollNumber = s2->rollNumber;
    s2->rollNumber = tempRollNumber;

    // Swap names
    strcpy(tempName, s1->name);
    strcpy(s1->name, s2->name);
    strcpy(s2->name, tempName);
}

int main() {
    struct Student s1, s2;

    // Input data for student 1
    printf("----------Student 1----------\n");
    printf("Enter Roll Number : ");
    scanf("%d", &(s1.rollNumber));
    printf("Enter Name : ");
    scanf("%s", s1.name);

    // Input data for student 2
    printf("----------Student 2----------\n");
    printf("Enter Roll Number : ");
    scanf("%d", &(s2.rollNumber));
    printf("Enter Name : ");
    scanf("%s", s2.name);

    printf("\n******Before Swapping******\n");
    printf("Student 1: Roll Number = %d, Name = %s\n", s1.rollNumber, s1.name);
    printf("Student 2: Roll Number = %d, Name = %s\n", s2.rollNumber, s2.name);

    // Swap the fields of the two structures
    swapFields(&s1, &s2);

    printf("\n******After Swapping******\n");
    printf("Student 1: Roll Number = %d, Name = %s\n", s1.rollNumber, s1.name);
    printf("Student 2: Roll Number = %d, Name = %s\n", s2.rollNumber, s2.name);

    return 0;
}