#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char timeString[9]; // Assuming the time string has a fixed length of 8 characters (hh:mm:ss)
    char *token;
    unsigned long hours, minutes, seconds;
    unsigned long totalSeconds;

    printf("Enter the time in the format hh:mm:ss: ");
    scanf("%8s", timeString);

    // Split the time string into hours, minutes, and seconds using strtok()
    token = strtok(timeString, ":");
    hours = strtoul(token, NULL, 10);
    token = strtok(NULL, ":");
    minutes = strtoul(token, NULL, 10);
    token = strtok(NULL, ":");
    seconds = strtoul(token, NULL, 10);

    // Compute the total seconds
    totalSeconds = hours * 3600 + minutes * 60 + seconds;

    printf("Total seconds: %lu\n", totalSeconds);

    return 0;
}
