#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void rotateStudents(struct Student* students, int size, int k) {
   
    struct Student* temp = malloc(k * sizeof(struct Student));

    memcpy(temp, students + (size - k), k * sizeof(struct Student));

    memmove(students + k, students, (size - k) * sizeof(struct Student));

   
    memcpy(students, temp, k * sizeof(struct Student));
    free(temp);
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

    int k;
    printf("Enter the number of positions to rotate: ");
    scanf("%d", &k);

    rotateStudents(students, size, k);
    printf("Updated Student Details (after rotating by %d positions):\n", k);
    for (int i = 0; i < size; i++) {
        printf("Roll Number: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n\n", students[i].marks);
    }

    free(students);

    return 0;
}
