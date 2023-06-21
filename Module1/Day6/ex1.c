#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseStringAndInitializeStructures(const char *input, struct Student *students, int numStudents) {
    const char *delimiters = " ";
    char *token;
    int i = 0;

    // Parse the input string using strtok()
    token = strtok((char *)input, delimiters);

    // Loop through the tokens and initialize the structures
    while (token != NULL && i < numStudents) {
        students[i].rollno = atoi(token);
        token = strtok(NULL, delimiters);

        strncpy(students[i].name, token, sizeof(students[i].name) - 1);
        students[i].name[sizeof(students[i].name) - 1] = '\0';
        token = strtok(NULL, delimiters);

        students[i].marks = atof(token);
        token = strtok(NULL, delimiters);

        i++;
    }
}

int main() {
    int numStudents;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    getchar();  // Consume the newline character

    struct Student *students = (struct Student *)malloc(numStudents * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    char input[100];

    printf("Enter the student details (rollno name marks): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';  // Remove the trailing newline character

    parseStringAndInitializeStructures(input, students, numStudents);

    // Print the initialized structures
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    free(students);

    return 0;
}
