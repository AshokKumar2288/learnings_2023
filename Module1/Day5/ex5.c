#include <stdio.h>

struct Student {
    char name[50];
    int age;
};

// Function to swap the fields of two structures using pointers
void swapFields(struct Student *s1, struct Student *s2) {
    struct Student temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

int main() {
    struct Student student1, student2;

    printf("Enter details for student 1:\n");
    printf("Name: ");
    scanf("%s", student1.name);
    printf("Age: ");
    scanf("%d", &student1.age);

    printf("\nEnter details for student 2:\n");
    printf("Name: ");
    scanf("%s", student2.name);
    printf("Age: ");
    scanf("%d", &student2.age);

    printf("\nBefore swapping:\n");
    printf("Student 1: Name: %s, Age: %d\n", student1.name, student1.age);
    printf("Student 2: Name: %s, Age: %d\n", student2.name, student2.age);

    swapFields(&student1, &student2);

    printf("\nAfter swapping:\n");
    printf("Student 1: Name: %s, Age: %d\n", student1.name, student1.age);
    printf("Student 2: Name: %s, Age: %d\n", student2.name, student2.age);

    return 0;
}
