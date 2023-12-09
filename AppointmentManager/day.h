// day ADT Header
// 
//Zongping Cui - Vinh Le - prog71985 - fall23 - Group 5: Group Project Assignment

#pragma once

#include "list.h"
#include "appointment.h"
#include <stdbool.h>

// TODO: capacity of appt
#define APPTNUMLIMIT 50
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
bool LoadAllDays(DAY* d[], char* filename);
bool SaveAllDays(DAY* d[], int num, char* filename);
//bool CopyDay(DAY* dest, DAY* src);

/*    useful   */
// array operate
bool AddApptToDay(DAY* d, APPOINTMENT appt);
bool RemoveApptFromDay(DAY* d, APPOINTMENT appt);

// R
void PrintDay(DAY* d);
/*    useful   */

// judge
bool CompareDay(DAY* a, DAY b);
bool CheckConflict_Day(DAY* a, APPOINTMENT newA);

// get 
int GetDay(DAY* d);
int GetMonth(DAY* d);
int GetYear(DAY* d);

// set
//bool SetDay(DAY* d, int);
//bool SetMonth(DAY* d, int);
//bool SetYear(DAY* d, int);

