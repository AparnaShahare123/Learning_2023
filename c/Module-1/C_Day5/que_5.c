#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void searchStudentsByName(const struct Student* students, int size, const char* targetName) {
    int found = 0;

    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].name, targetName) == 0) {
            printf("Roll Number: %d\n", students[i].rollno);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n\n", students[i].marks);
            found = 1;
        }
    }

    if (!found) {
        printf("Student with name '%s' not found.\n", targetName);
    }
}

int main() {
    int size;
    printf("-----Aparna Bhaskar Shahare-----\n");
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

    char targetName[20];
    printf("Enter the name of the student to search: ");
    scanf("%s", targetName);

    // Perform the search operation based on name
    printf("Search Results:\n");
    searchStudentsByName(students, size, targetName);

    free(students);

    return 0;
}
