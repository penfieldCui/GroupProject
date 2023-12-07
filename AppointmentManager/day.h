// ADT of a day to hold appointments
// program71985 - fall23
// zongping cui
#pragma once

#include "list.h"
#include "appointment.h"
#include <stdbool.h>


#define MAXAPPTPERDAY 50

typedef struct day {
	PLISTNODE appts;
	int day;
	int month;
	int year;
}DAY;

//DMA
DAY* InitialD(int day,int month,int year);
void DestroyDay(DAY* d);

//I/O
//load
//save
//bool CopyDay(DAY* dest, DAY* src);


// R
void PrintDay(DAY* d);

// judge
//bool CompareDay(DAY* a, DAY* b);


// get 
int GetDay(DAY* d);
int GetMonth(DAY* d);
int GetYear(DAY* d);

// set
//bool SetDay(DAY* d, int);
//bool SetMonth(DAY* d, int);
//bool SetYear(DAY* d, int);