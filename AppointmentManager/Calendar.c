// function to diplay calader
// program71985 - fall23
// zongping cui
#define _CRT_SECURE_NO_WARNINGS
#include "Calendar.h"
#include <stdbool.h>
#include <stdio.h>


// return the number of days in a given month
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

// print the calendar
void PrintCalendar(int month, int year) {


    printf("Calendar for %02d/%d\n", month, year);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");

    int days = getNumberOfDays(month, year);
    int startDay = getDayOfWeek(1, month, year);

    // adjusting output
    startDay = (startDay + 5) % 7;

    for (int i = 0; i < startDay; i++) {
        printf("    ");
    }

    // print the days
    for (int i = 1; i <= days; i++) {

        // if the day has appointment
        if ((i + startDay - 1) % 7 == 0 || (i + startDay - 1) % 7 == 6) {
            printf("\033[0m"); // Set text color to red
        }

        printf("%3d ", i);

        if ((i + startDay) % 7 == 0) {
            printf("\n"); 
        }
        //else if (i == days) {
        //    printf("\033[0m\n"); // Reset text color to default
        //}
        //else {
        //    printf("\033[0m"); // Reset text color to default
        //}
    }
    printf("\n");
}

bool nextMonth(int* month, int* year) {
    if (*month == 12) {
        *month = 1;
        *year += 1;
    }
    else {
        *month += 1;
    }   
}

// test
//int main() {
//    //int month, year;
//    printf("Enter month and year (MM YYYY): \n");
//    //scanf("%d %d", &month, &year);
//    DAY* d = InitialD(12,12,2023);
//
//    int month = GetMonth(d);
//    int year = GetYear(d);
//
//    PrintCalendar(month, year);
//
//    nextMonth(&month,&year);
//    PrintCalendar(month, year);
//    DestroyDay(d);
//    return 0;
//}
