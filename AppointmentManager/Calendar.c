#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Function to return the number of days in a given month
int getNumberOfDays(int month, int year) {
    switch (month) {
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            return 29;
        else
            return 28;
    default:
        return 31;
    }
}

// Zeller's Congruence to find the day of week
int getDayOfWeek(int day, int month, int year) {
    if (month < 3) {
        month += 12;
        year -= 1;
    }
    int k = year % 100;
    int j = year / 100;
    int dayOfWeek = (day + 13 * (month + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
    return dayOfWeek;
}

// Function to print the calendar
void printCalendar(int month, int year) {
    printf("Calendar for %02d/%d\n", month, year);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");

    int days = getNumberOfDays(month, year);
    int startDay = getDayOfWeek(1, month, year);

    // Adjusting for Zeller's Congruence output
    startDay = (startDay + 5) % 7;

    // Print spaces for the first day
    for (int i = 0; i < startDay; i++) {
        printf("    ");
    }

    // Print the days
    for (int i = 1; i <= days; i++) {
        // Check if the day is weekend (Sunday or Saturday)
        if ((i + startDay - 1) % 7 == 0 || (i + startDay - 1) % 7 == 6) {
            printf("\033[31m"); // Set text color to red
        }

        printf("%3d ", i);

        if ((i + startDay) % 7 == 0) {
            printf("\033[0m\n"); // Reset text color to default
        }
        else if (i == days) {
            printf("\033[0m\n"); // Reset text color to default
        }
        else {
            printf("\033[0m"); // Reset text color to default
        }
    }
    printf("\n");
}

int main() {
    int month, year;
    printf("Enter month and year (MM YYYY): ");
    scanf("%d %d", &month, &year);
    printCalendar(month, year);
    return 0;
}
