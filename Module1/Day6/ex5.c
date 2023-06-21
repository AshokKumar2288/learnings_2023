#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 100

struct Student {
    char name[MAX_NAME_LENGTH];
    int age;
    float gpa;
};

struct Student searchStudentByName(struct Student students[], int numStudents, const char* name) {
    struct Student notFoundStudent = {"", 0, 0.0};
  
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, name) == 0) {
            return students[i];
        }
    }
  
    return notFoundStudent;
}

int main() {
    struct Student students[MAX_STUDENTS] = {
        {"John", 20, 3.5},
        {"Alice", 21, 3.9},
        {"Bob", 19, 3.2},
        // Add more students here
    };
    int numStudents = 3;  // Number of students in the array
    
    // Example usage of the search function
    const char* searchName = "Alice";
    struct Student foundStudent = searchStudentByName(students, numStudents, searchName);
    
    if (strcmp(foundStudent.name, "") == 0) {
        printf("Student not found.\n");
    } else {
        printf("Student found: %s\n", foundStudent.name);
        printf("Age: %d\n", foundStudent.age);
        printf("GPA: %.2f\n", foundStudent.gpa);
    }
    
    return 0;
}
