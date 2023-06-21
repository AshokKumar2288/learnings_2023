#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

// Comparison function for qsort
int compare(const void* a, const void* b) {
    const struct Student* studentA = (const struct Student*)a;
    const struct Student* studentB = (const struct Student*)b;
    
    // Sort in descending order based on marks
    if (studentA->marks < studentB->marks)
        return 1;
    else if (studentA->marks > studentB->marks)
        return -1;
    else
        return 0;
}

void sortArray(struct Student* studentArray, int size) {
    qsort(studentArray, size, sizeof(struct Student), compare);
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    fflush(stdin);

    struct Student studentArray[size];

    printf("Enter student details:\n");
    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &studentArray[i].rollno);
        fflush(stdin);

        printf("Name: ");
        fgets(studentArray[i].name, sizeof(studentArray[i].name), stdin);
        studentArray[i].name[strcspn(studentArray[i].name, "\n")] = '\0';

        printf("Marks: ");
        scanf("%f", &studentArray[i].marks);
        fflush(stdin);
    }

    sortArray(studentArray, size);

    printf("\nSorted Student Data (Descending Order):\n");
    for (int i = 0; i < size; i++) {
        printf("Roll No: %d, Name: %s, Marks: %.2f\n", studentArray[i].rollno, studentArray[i].name, studentArray[i].marks);
    }

    return 0;
}
