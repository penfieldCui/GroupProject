#pragma once

#include "day.h"
#include <time.h>

#define DAYLIMIT 100  //don't care about more than 3 months

// Display
void PrintCalendar(DAY* days[], int month, int year, struct tm local_time);
void PrintMonths(DAY* days[], int num_month, struct tm time);

// Judge
bool IsValidDate(int day, int month, int year);

/*    useful   */
// SEARCH   
// by Chris
// not 0 -  num of day found in days
// -1 no day found
// int SearchARangeOfDayInArrayByDate(DAY* days[], DAY* selected_days[], int capacity, struct start_tm, struct end_tm);
// 
// return index of day in days
//			return - 1 : not found
int SearchDayInArrayByDate(DAY* days[], int capacity, struct tm);

// return appt match same id
APPOINTMENT* SearchApptById(DAY* days[], int capacity, int id);
/*    useful   */

// TODO: 1:20 not sure thats the best place to do generate
int GenerateUidOfAppt(DAY* days[], int capacity, struct tm time);

// R
struct tm* GetCurrentTime();
int GetCapacity();
int GetNumOfDays(DAY* days[], int capacity);

void DestroyAllDay(DAY* days[]);