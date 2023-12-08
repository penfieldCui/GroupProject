#pragma once

#include "day.h"
#include <time.h>

void PrintCalendar(int month, int year);


// return index of day in days
int SearchDayInArray(DAY** days, int capacity, struct tm);

int GetNumOfDays(DAY* days[], int capacity);