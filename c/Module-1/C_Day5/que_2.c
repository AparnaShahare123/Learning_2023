#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void initializeStudents(struct Student* students, int size) {
    for (int i = 0; i < size; i++) {
        students[i].rollno = i + 1;
        strcpy(students[i].name, "");
        students[i].marks = 0.0;
    }
}

int main() {
    int size;
    printf("-----Aparna Bhaskar Shahare-----\n");
    printf("Enter the number of students: ");
    scanf("%d", &size);

    struct Student* students = malloc(size * sizeof(struct Student));

    // Initialize the student structures using the function
    initializeStudents(students, size);

    // Display the initialized student details
    printf("\nStudent Details:\n");
    for (int i = 0; i < size; i++) {
        printf("Roll Number: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n\n", students[i].marks);
    }

    free(students);

    return 0;
}
