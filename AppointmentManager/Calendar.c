// function to display calendar
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
    //strptime();

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

        //if (i == days) 
        //    printf("\033[0m\n");

        printf("%3d ", i);

        if ((i + startDay) % 7 == 0) { //end of week
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
    return true;
}

int GetNumOfDays(DAY* days[], int capacity) {
    

    int num = 0;
    for (int i = 0; i < capacity; i++) {
        if (days[i] != NULL)
            num++;
    }
    return num;
}

int SearchDayInArray(DAY** days, int capacity, struct tm time) {
    DAY inputD = CreateEmptyD(time.tm_mday, time.tm_mon+1, time.tm_year + 1900);
    for (int i = 0; i < capacity; i++) {
        if(CompareDay(days[i], inputD))
            return i;
    }
    
    return -1;
}

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
//
//    return 0;
//}
