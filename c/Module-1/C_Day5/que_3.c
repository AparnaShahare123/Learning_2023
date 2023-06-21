#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void displayStudents(const struct Student* students, int size) {
    for (int i = 0; i < size; i++) {
        printf("Roll Number: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n\n", students[i].marks);
    }
}

int main() {
    int size;

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

    // Display all student details using the function
    printf("----Student Details----\n");
    displayStudents(students, size);

    free(students);

    return 0;
}
