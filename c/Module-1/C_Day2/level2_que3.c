#include<stdio.h>
#include <string.h>

int main()
 {
    char *names[] = { "Santosh", "Amol", "Santosh Jain", "Kishore", "Rahul", "Amolkumar", "Hemant"};
    int numNames = sizeof(names) / sizeof(names[0]);
// Bubble sort
    for (int i = 0; i < numNames - 1; i++) 
    {
        for (int j = 0; j < numNames - i - 1; j++)
        {
            if (strcmp(names[j], names[j + 1]) > 0)
            {
                char *temp = names[j];
                names[j] = names[j + 1];
                names[j + 1] = temp;
            }
        }
    }
    printf("Sorted names:\n");
    for (int i = 0; i < numNames; i++) 
    {
        printf("%s\n", names[i]);
    }

    return 0;
}