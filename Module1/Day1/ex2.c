#include <stdio.h>

int main() {
  
    int roll_no;
    char name[100];
    float physics_marks, math_marks, chemistry_marks;
    
    printf("Enter Roll No: ");
    scanf("%d", &roll_no);
    
    printf("Enter Name: ");
    scanf("%s", name);
    
    printf("Enter Marks in Physics: ");
    scanf("%f", &physics_marks);
    
    printf("Enter Marks in Math: ");
    scanf("%f", &math_marks);
    
    printf("Enter Marks in Chemistry: ");
    scanf("%f", &chemistry_marks);
    
    
    float total_marks = physics_marks + math_marks + chemistry_marks;
    float percentage = (total_marks / 300) * 100;
    
    
    printf("\n--- Student Summary ---\n");
    printf("Roll No: %d\n", roll_no);
    printf("Name: %s\n", name);
    printf("Marks in Physics: %.2f\n", physics_marks);
    printf("Marks in Math: %.2f\n", math_marks);
    printf("Marks in Chemistry: %.2f\n", chemistry_marks);
    printf("Total Marks: %.2f\n", total_marks);
    printf("Percentage: %.2f%%\n", percentage);
    
    return 0;
}
