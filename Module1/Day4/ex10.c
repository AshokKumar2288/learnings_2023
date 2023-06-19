#include <stdio.h>
#include <string.h>

void rotateString(char* str, int n, char direction) {
    int len = strlen(str);
    char temp[len + 1];
    
    if (direction == 'L' || direction == 'l') {
        strncpy(temp, str, n);
        temp[n] = '\0';
        strcpy(str, str + n);
        strcat(str, temp);
    } else if (direction == 'R' || direction == 'r') {
        strncpy(temp, str + len - n, n);
        temp[n] = '\0';
        memmove(str + n, str, len - n + 1);
        strncpy(str, temp, n);
    }
}

int main() {
    char str[20]; // Assuming the string has a maximum length of 20 characters
    int n;
    char direction;

    printf("Enter a string: ");
    scanf("%19s", str);

    printf("Enter the number of rotations: ");
    scanf("%d", &n);

    printf("Enter the rotation direction (L/R): ");
    scanf(" %c", &direction);

    rotateString(str, n, direction);

    printf("Rotated string: %s\n", str);

    return 0;
}
