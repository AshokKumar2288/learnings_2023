#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[20]; // Assuming the string has a maximum length of 20 characters

    printf("Enter a string: ");
    scanf("%s", str);

    // Using atoi() function
    int num1 = atoi(str);

    // Using sscanf() function
    int num2;
    sscanf(str, "%d", &num2);

    printf("Using atoi(): %d\n", num1);
    printf("Using sscanf(): %d\n", num2);

    return 0;
}
