#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdbool.h>
#include <stdio.h>

#define MAXSIZE 100
#define MAXTEXT 255
#define MAXDATE 11
#define MAXTIME 6

typedef enum status_enum {
	NONE = 0, NOT_EXPIRED = 1, EXPIRED = 2 , CANCELED = 3
}STATUS_ENUM;

typedef struct appointment {

	int id;

	char title[MAXSIZE];

	//char date[MAXDATE]; // format: yyyy-MM-dd
	//char time[MAXTIME];  // format: hh:mm

	struct tm start_time; // use struct tm to represent start time
	int duration_minutes; // duration minutes

	char location[MAXSIZE];
	char description[MAXTEXT];

	int appointment_status;


}APPOINTMENT;




//C
APPOINTMENT CreateAppt(int id, char* title, struct tm start_time, int duration, char* location, char* description);
void DestroyAppt(APPOINTMENT a);

bool CopyAppt(APPOINTMENT* dest, APPOINTMENT src);

// judge

bool CompareAppt(APPOINTMENT a, APPOINTMENT b);
bool CheckConflict(APPOINTMENT a, APPOINTMENT b);

// display
void PrintAppt(APPOINTMENT appt);

// get set
int GetAppId(APPOINTMENT appt);

void SetAppId(APPOINTMENT* appt, int id);

void GetAppTitle(APPOINTMENT appt, char* title);

void SetApptTitle(APPOINTMENT* appt, char* title);

struct tm GetApptStartTime(APPOINTMENT appt);

void SetApptStartTime(APPOINTMENT* appt, struct tm start_time);

int GetApptDuration(APPOINTMENT appt);

void SetApptDuration(APPOINTMENT* appt, int duration_minutes);



void GetApptLocation(APPOINTMENT appt, char* location);

void SetApptLocation(APPOINTMENT* appt, const char* location);

void GetApptDescription(APPOINTMENT appt, char* description);

void SetApptDescription(APPOINTMENT* appt, const char* description);

STATUS_ENUM GetApptStatus(APPOINTMENT appt);

void SetApptStatus(APPOINTMENT* appt, STATUS_ENUM status);
