#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getDaysInMonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

int calculateDaysElapsed(int day1, int month1, int year1, int day2, int month2, int year2) {
    int totalDays = 0;

    // Calculate days for year1
    for (int i = year1 + 1; i < year2; i++) {
        totalDays += isLeapYear(i) ? 366 : 365;
    }

    // Calculate days for year1 partial year
    for (int i = month1 + 1; i <= 12; i++) {
        totalDays += getDaysInMonth(i, year1);
    }
    totalDays += getDaysInMonth(month1, year1) - day1;

    // Calculate days for year2 partial year
    for (int i = 1; i < month2; i++) {
        totalDays += getDaysInMonth(i, year2);
    }
    totalDays += day2;

    return totalDays;
}

int main() {
    char date1[11]; // DD/MM/YYYY
    char date2[11]; // DD/MM/YYYY
    int day1, month1, year1;
    int day2, month2, year2;

    printf("Enter date 1 (DD/MM/YYYY): ");
    scanf("%10s", date1);
    sscanf(date1, "%d/%d/%d", &day1, &month1, &year1);

    printf("Enter date 2 (DD/MM/YYYY): ");
    scanf("%10s", date2);
    sscanf(date2, "%d/%d/%d", &day2, &month2, &year2);

    int daysElapsed = calculateDaysElapsed(day1, month1, year1, day2, month2, year2);
    printf("Number of days elapsed: %d\n", daysElapsed);

    return 0;
}
