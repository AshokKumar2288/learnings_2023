#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void copyFile(FILE *sourceFile, FILE *destinationFile, int caseOption);

int main(int argc, char *argv[]) {
    FILE *sourceFile, *destinationFile;
    char ch;
    int caseOption = 0;

    if (argc < 3) {
        printf("Insufficient arguments.\n");
        printf("Usage: ./cp [-u | -l | -s] source_file destination_file\n");
        return 1;
    }

    // Open the source file in read mode
    sourceFile = fopen(argv[argc - 2], "r");

    if (sourceFile == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }

    // Open the destination file in write mode
    destinationFile = fopen(argv[argc - 1], "w");

    if (destinationFile == NULL) {
        printf("Unable to create the destination file.\n");
        fclose(sourceFile);
        return 1;
    }

    // Check the option for handling the text case
    if (argc == 4) {
        if (argv[1][0] == '-') {
            switch (tolower(argv[1][1])) {
                case 'u':
                    caseOption = 1;  // Upper case
                    break;
                case 'l':
                    caseOption = 2;  // Lower case
                    break;
                case 's':
                    caseOption = 3;  // Sentence case
                    break;
                default:
                    printf("Invalid option.\n");
                    fclose(sourceFile);
                    fclose(destinationFile);
                    return 1;
            }
        } else {
            printf("Invalid option.\n");
            fclose(sourceFile);
            fclose(destinationFile);
            return 1;
        }
    }

    // Copy the file content with the specified case handling
    copyFile(sourceFile, destinationFile, caseOption);

    printf("File copied successfully.\n");

    // Close the files
    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}

void copyFile(FILE *sourceFile, FILE *destinationFile, int caseOption) {
    char ch;
    int sentenceStart = 1;

    while ((ch = fgetc(sourceFile)) != EOF) {
        switch (caseOption) {
            case 1:  // Upper case
                ch = toupper(ch);
                break;
            case 2:  // Lower case
                ch = tolower(ch);
                break;
            case 3:  // Sentence case
                if (sentenceStart) {
                    ch = toupper(ch);
                    sentenceStart = 0;
                } else {
                    ch = tolower(ch);
                }

                if (ch == '.' || ch == '!' || ch == '?') {
                    sentenceStart = 1;
                }
                break;
        }

        fputc(ch, destinationFile);
    }
}
