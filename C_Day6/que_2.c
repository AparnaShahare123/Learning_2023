#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 4096

void copyFile(FILE *source, FILE *destination, int option);

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("Insufficient arguments.\n");
        printf("Usage: ./cp [-u | -l | -s] source_file destination_file\n");
        return 1;
    }

    int option = 0;
    if (argc > 3) {
        char *arg = argv[1];
        if (arg[0] == '-') {
            switch (arg[1]) {
                case 'u':
                    option = 1;
                    break;
                case 'l':
                    option = 2;
                    break;
                case 's':
                    option = 3;
                    break;
                default:
                    printf("Invalid option.\n");
                    return 1;
            }
        } else {
            printf("Invalid option.\n");
            return 1;
        }
    }

    FILE *sourceFile, *destinationFile;
    sourceFile = fopen(argv[argc - 2], "r");
    if (sourceFile == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }

    destinationFile = fopen(argv[argc - 1], "w");
    if (destinationFile == NULL) {
        printf("Unable to create the destination file.\n");
        fclose(sourceFile);
        return 1;
    }

    copyFile(sourceFile, destinationFile, option);

    printf("File copied successfully.\n");

    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}

void copyFile(FILE *source, FILE *destination, int option)
{
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, source)) > 0)
    {
        if (option == 1)
        { // -u: Convert to upper case
            for (size_t i = 0; i < bytesRead; i++)
            {
                buffer[i] = toupper(buffer[i]);
            }
        } else if (option == 2) { // -l: Convert to lower case
            for (size_t i = 0; i < bytesRead; i++)
            {
                buffer[i] = tolower(buffer[i]);
            }
        } else if (option == 3) { // -s: Convert to purely upper case
            for (size_t i = 0; i < bytesRead; i++) 
            {
                if (isalpha(buffer[i]))
                {
                    buffer[i] = toupper(buffer[i]);
                }
            }
        }

        fwrite(buffer, 1, bytesRead, destination);
    
    }
}    