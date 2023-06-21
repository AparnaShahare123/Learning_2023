#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void swapStudents(struct Student* students, int index1, int index2) {
    struct Student temp = students[index1];
    students[index1] = students[index2];
    students[index2] = temp;
}

int main() {
    int size;
    printf("---Aparna Bhaskar Shahare---\n");
    printf("Enter the number of students: ");
    scanf("%d", &size);

    struct Student* students = malloc(size * sizeof(struct Student));

    printf("Enter the student details:\n");
    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);

        printf("Enter roll number: ");
        scanf("%d", &students[i].rollno);

        printf("Enter name: ");
        scanf("%s", students[i].name);

        printf("Enter marks: ");
        scanf("%f", &students[i].marks);

        printf("\n");
    }

    int index1, index2;
    printf("Enter the indexes of the students to swap: ");
    scanf("%d %d", &index1, &index2);

    // Perform the swap operation
    swapStudents(students, index1, index2);

    // Display the updated student details
    printf("Updated Student Details:\n");
    for (int i = 0; i < size; i++) {
        printf("Roll Number: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %f\n\n", students[i].marks);
    }

    free(students);

    return 0;
}
