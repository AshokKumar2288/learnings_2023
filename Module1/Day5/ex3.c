#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

// Function to calculate the difference between two time periods
struct Time calculateTimeDifference(struct Time t1, struct Time t2) {
    struct Time difference;
    int totalSeconds1, totalSeconds2, diffSeconds;

    totalSeconds1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    totalSeconds2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;

    diffSeconds = totalSeconds1 - totalSeconds2;

    difference.hours = diffSeconds / 3600;
    diffSeconds %= 3600;
    difference.minutes = diffSeconds / 60;
    difference.seconds = diffSeconds % 60;

    return difference;
}

int main() {
    struct Time time1, time2, difference;

    printf("Enter the first time period (hours minutes seconds): ");
    scanf("%d %d %d", &time1.hours, &time1.minutes, &time1.seconds);

    printf("Enter the second time period (hours minutes seconds): ");
    scanf("%d %d %d", &time2.hours, &time2.minutes, &time2.seconds);

    difference = calculateTimeDifference(time1, time2);

    printf("\nDifference: %d hours, %d minutes, %d seconds\n", difference.hours, difference.minutes, difference.seconds);

    return 0;
}
