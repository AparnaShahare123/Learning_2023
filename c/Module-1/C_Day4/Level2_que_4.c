#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct Student {
    int rollNumber;
    char name[50];
};

struct Student* modifyStudent(struct Student* student) {
    // Modify the members of the structure
    student->rollNumber = 12345;
    strcpy(student->name, "Aparna Shahare");

    return student;
}

int main() {
    struct Student s;
    struct Student* modifiedStudent;

    // Input data for the student
    printf("------Aparna Shahare------\n");
    printf("Enter Roll Number: ");
    scanf("%d", &(s.rollNumber));
    printf("Enter Name: ");
    scanf("%s", s.name);

    // Pass the pointer to the structure and get the modified structure pointer
    modifiedStudent = modifyStudent(&s);

    // Display the modified structure
    printf("\nModified Student:\n");
    printf("Roll Number: %d\n", modifiedStudent->rollNumber);
    printf("Name: %s\n", modifiedStudent->name);

    return 0;
}
