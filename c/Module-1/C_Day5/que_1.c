#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseStringAndInitialize(char* input, struct Student* students, int size) {
    char* token;
    int i = 0;

    token = strtok(input, " ");

    while (token != NULL && i < size) {
        students[i].rollno = atoi(token);

        token = strtok(NULL, " ");
        if (token == NULL) {
            printf("Invalid input format.\n");
            return;
        }

        strcpy(students[i].name, token);

        token = strtok(NULL, " ");
        if (token == NULL) {
            printf("Invalid input format.\n");
            return;
        }

        students[i].marks = atof(token);

        i++;
        token = strtok(NULL, " ");
    }
}

int main() {
    int size;
    printf("---Aparna Bhaskar Shahare---\n");
    printf("Enter the number of students: ");
    scanf("%d", &size);

    getchar(); // Clear the newline character from the input buffer

    struct Student* students = malloc(size * sizeof(struct Student));

    printf("Enter the student details in the format (rollno name marks):\n");
    for (int i = 0; i < size; i++) {
        char input[100];
        fgets(input, sizeof(input), stdin);

        // Remove trailing newline character
        if (input[strlen(input) - 1] == '\n')
            input[strlen(input) - 1] = '\0';

        parseStringAndInitialize(input, &students[i], 1);
    }

    printf("\nStudent Details:\n");
    for (int i = 0; i < size; i++) {
        printf("Roll Number: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n\n", students[i].marks);
    }

    free(students);

    return 0;
}