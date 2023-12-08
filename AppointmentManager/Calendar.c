// function to display calendar
// program71985 - fall23
// zongping cui
#define _CRT_SECURE_NO_WARNINGS
#include "Calendar.h"
#include "menu.h"
#include <stdbool.h>
#include <stdio.h>



//8th December - Chris
//int SearchARangeOfDayInArrayByDate(DAY* days[], DAY* selected_days[], int capacity, struct tm start_tm, struct tm end_tm) {
//    for () 
//}


// C 
// let user input information and creat a appointment (also generate the uid)
bool InputAndAddAppointmentToDay(DAY* days[]) {
    int capacity = GetCapacity();
    struct tm* chosen_date = GetCurrentTime();
    printf("Input the date you want to add appointment.\n");
    ChooseADay(chosen_date);

   
    int dd = chosen_date->tm_mday;
    int mm = chosen_date->tm_mon+1;
    int yy = chosen_date->tm_year + 1900;
    int index = SearchDayInArrayByDate(days, capacity, *chosen_date);
    
    if (index == -1) {
        int num = GetNumOfDays(days, capacity);
        if (num == capacity) {
            printf("no room for more day, please select other date.\n");
            return false;
        }
        days[num] = InitialD(dd, mm, yy);
        index = num;
    }
    
    
    char buffer[MAXSIZE];
    //title
    char title[MAXSIZE];
    printf("Enter title: \n");
    ReadStream(title, MAXSIZE, stdin);
    //start_time
    char time_str[MAXSIZE];
    int formatted = false;
    do {
        printf("Enter time (in format hh:mm): \n");
        ReadStream(time_str, MAXREAD, stdin);
        if (sscanf(time_str, "%d:%d", &chosen_date->tm_hour, &chosen_date->tm_min) == 2) {
            formatted = true;
        }
        else
            printf("please retry, error formatted\n");
    } while (!formatted);

    //duration_minutes
    printf("Enter duration in minutes: \n");
    ReadStream(buffer, MAXSIZE, stdin);
    int duration = atoi(buffer);

    //description
    printf("Enter description of that appointment: \n");
    char description[MAXREAD];
    ReadStream(description, MAXREAD, stdin);
    // id
    int id = GenerateUidOfAppt(days, capacity, *chosen_date);
    APPOINTMENT newA = CreateAppt(id,title,*chosen_date,duration, description, NOT_EXPIRED);

    bool is_add = false;

    if (CheckConflict_Day(days[index], newA)) {
        printf("! Appointment conflict to existing appointment, go back to previous level\n");
    }
    else
    {
        printf("\n! Adding appointment: \n\n");
        PrintAppt(newA);
        if (ChooseYorN()) {
            is_add = AddApptToDay(days[index], newA);
            if (is_add) {
                return true;
            }
        }
            
    }

    // clean the empty day
    if (days[index]->appts == NULL) {
        DestroyDay(days[index]);
        days[index] = NULL;
    }
    return false;

}


// return the number of days in a given month
static int getNumberOfDays(int month, int year) {
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
static int getDayOfWeek(int month, int year) {
    if (month < 3) {
        month += 12;
        year -= 1;
    }
    int k = year % 100;
    int j = year / 100;
    int dayOfWeek = (1 + 13 * (month + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
    return dayOfWeek;
}


// display
// print the calendar with multiple months
void PrintMonths(DAY* days[], int num_month, struct tm time) {
    
    
    int m = time.tm_mon + 1;
    int y = time.tm_year + 1900;
    for (int i = 0; i < num_month; i++) {
        PrintCalendar(days, m , y, time);
        if (++m > 12) {
            m = 1;
            y++;
        }
    }
}

// print the calendar
void PrintCalendar(DAY* days[],int month, int year, struct tm local_time) {
    //strptime();

    printf("Calendar for %02d/%d\n", month, year);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");

    DAY today = CreateEmptyD(local_time.tm_mday, local_time.tm_mon+1, local_time.tm_year+1900);

    int num_day = getNumberOfDays(month, year);
    int startDay = getDayOfWeek(month, year);

    // adjusting output
    startDay = (startDay + 5) % 7;

    for (int i = 0; i < startDay; i++) {
        printf("    ");
    }

    // print the days
    for (int i = 1; i <= num_day; i++) {
        struct tm time;
        time.tm_mday = i;
        time.tm_mon = month - 1;
        time.tm_year = year - 1900;

        //
        if (SearchDayInArrayByDate(days, GetCapacity(), time)!= -1)
            if (i == GetDay(&today) && month == GetMonth(&today)) {
                printf("\033[31m"); // RED : today with appt
            }
            else
                printf("\033[1;34m"); // BLUE day with appt
       

        if (i == GetDay(&today) && month == GetMonth(&today)) 
            if (SearchDayInArrayByDate(days, GetCapacity(), time) == -1)
                printf("\033[32m"); // GREEN:  today with no appt to green
            
        

        printf("%3d ", i);

        if ((i + startDay) % 7 == 0) {
            printf("\033[0m\n"); // Reset text color to default
        }
        else if (i == num_day) {
            printf("\033[0m\n"); // Reset text color to default
        }
        else {
            printf("\033[0m"); // Reset text color to default
        }
    }
    printf("\n");
}


// R
struct tm* GetCurrentTime() {
    time_t current_time;
    time(&current_time);

    // Convert to local time format
    return localtime(&current_time); // to expired some appointments when load
}

int GetCapacity() {
    return DAYLIMIT;
}

int GetNumOfDays(DAY* days[], int capacity) {
    
    int num = 0;
    for (int i = 0; i < capacity; i++) {
        if (days[i] != NULL)
            num++;
    }
    return num;
}



// Judge
// check input date
bool IsValidDate(int day, int month, int year){
    // Check if the year, month, and day are within the expected range
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }

    //int maxMDay = getNumberOfDays(month, year);
    return day <= getNumberOfDays(month, year);
    //if (month == 2) {
    //    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) { // Leap year
    //        return day <= 29;
    //    }
    //    else {
    //        return day <= 28;
    //    }
    //}

    //// April, June, September, and November have 30 days
    //if (month == 4 || month == 6 || month == 9 || month == 11) {
    //    return day <= 30;
    //}

    // Other months have 31 days, already checked at the start
    //return true;
}

// SEARCH
int SearchDayInArrayByDate(DAY* days[], int capacity, struct tm time) {
    DAY inputD = CreateEmptyD(time.tm_mday, time.tm_mon+1, time.tm_year + 1900);
    for (int i = 0; i < capacity; i++) {
        if(CompareDay(days[i], inputD))
            return i;
    }
    
    return -1;
}

APPOINTMENT* SearchApptById(DAY* days[], int capacity, int id) {
    for (int i = 0; i < capacity; i++) {
        if (days[i] != NULL) {
            PLISTNODE tmpAppt = SearchApptInListById(days[i]->appts, id);
            if (tmpAppt != NULL) {
                return &(tmpAppt->data);
            }
        }
        
    }
    return NULL;
}

// use time to generate uid
int GenerateUidOfAppt(DAY* days[], int capacity, struct tm time) {

    int y = time.tm_year % 100; //  maybe 200 is slightly better in some case
    int m = time.tm_mon + 1;
    int d = time.tm_mday;

    int tmp_id = y * 1000000 + m * 10000 + d * 100 + 1;

    int count = 0;
    // TODO: increase efficiency maybe?
    while (SearchApptById(days, capacity, tmp_id) != NULL && count < APPTNUMLIMIT) {//100 most
        tmp_id++;
        count++;
    }

    if (count == APPTNUMLIMIT) {
        printf("Daily appointment limit reached, pleas arrange to another day. \n");
        return -1;
    }

    return tmp_id;
}

// DMA
void DestroyAllDay(DAY* days[]) {
    int capacity = GetCapacity();
    for (int i = 0; i < capacity; i++) {
        if (days[i] != NULL){
            DestroyDay(days[i]);
            days[i] = NULL; //reset to NULL;
        }
    }
}

