#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

// Comparison function for sorting in descending order based on marks
int compareDescendingMarks(const void* a, const void* b) {
    const struct Student* studentA = (const struct Student*)a;
    const struct Student* studentB = (const struct Student*)b;

    if (studentA->marks < studentB->marks) {
        return 1; // Swap if marks of A are less than marks of B
    } else if (studentA->marks > studentB->marks) {
        return -1; // Don't swap if marks of A are greater than marks of B
    }

    return 0; // Marks are equal, maintain the original order
}

void sortStudentsByMarksDescending(struct Student* students, int size) {
    qsort(students, size, sizeof(struct Student), compareDescendingMarks);
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

    // Sort the students array by marks in descending order
    sortStudentsByMarksDescending(students, size);

    // Display the sorted student details
    printf("Student Details_Sorted by Marks - Descending:\n");
    for (int i = 0; i < size; i++) {
        printf("Roll Number: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n\n", students[i].marks);
    }

    free(students);

    return 0;
}
