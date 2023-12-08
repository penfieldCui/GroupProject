// ADT of a day to hold appointments
// program71985 - fall23
// zongping cui
#pragma once

#include "list.h"
#include "appointment.h"
#include <stdbool.h>

typedef struct day {
	PLISTNODE appts;
	int day;
	int month;
	int year;
}DAY;

DAY CreateEmptyD(int day, int month, int year);
//DMA
DAY* InitialD(int day,int month,int year);
void DestroyDay(DAY* d);

//I/O
//load
bool SaveAllDays(DAY* d[], int num, char* filename);
//bool CopyDay(DAY* dest, DAY* src);

// array operate
bool AddApptToDay(DAY* d, APPOINTMENT appt);
bool RemoveApptFromDay(DAY* d, APPOINTMENT appt);

// R
void PrintDay(DAY* d);

// judge
bool CompareDay(DAY* a, DAY b);

// get 
int GetDay(DAY* d);
int GetMonth(DAY* d);
int GetYear(DAY* d);

// set
//bool SetDay(DAY* d, int);
//bool SetMonth(DAY* d, int);
//bool SetYear(DAY* d, int);

