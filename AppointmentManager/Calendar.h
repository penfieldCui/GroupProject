#pragma once

#include "day.h"
#include <time.h>

#define DAYLIMIT 100  //don't care about appointment more than 3 months


// Display
void PrintCalendar(DAY* days[], int month, int year);
void PrintMonths(DAY* days[], int num_month, int start_month, int start_year);

// Judge
bool IsValidDate(int day, int month, int year);

// SEARCH
// return index of day in days
int SearchDayInArray(DAY* days[], int capacity, struct tm);

// R
struct tm* GetCurrentTime();
int GetCapacity();
int GetNumOfDays(DAY* days[], int capacity);

void DestroyAllDay(DAY* days[]);