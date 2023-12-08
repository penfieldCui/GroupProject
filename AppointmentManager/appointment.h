//ADT of apptoinmet that holds information and time
// program71985 - fall23
// zongping cui
#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdbool.h>
#include <stdio.h>

#define MAXSIZE 100
#define MAXTEXT 255
#define MAXREAD 270
//#define MAXDATE 11

typedef enum status_enum {
	NONE = 0, NOT_EXPIRED = 1, EXPIRED = 2 , CANCELED = 3
	// Note: Dec 7, canceled might be oudated, but it dosent matter currently
}STATUS_ENUM;

typedef struct appointment {

	int id;

	char title[MAXSIZE];

	struct tm start_time; // use struct tm to represent start time
	int duration_minutes; // duration minutes

	char location[MAXSIZE];
	char description[MAXTEXT];

	int appointment_status;


}APPOINTMENT;




//C

APPOINTMENT CreateAppt(int id, char* title, struct tm start_time, int duration, char* location, char* description, int appointment_status);
void DestroyAppt(APPOINTMENT* a);


bool CopyAppt(APPOINTMENT* dest, APPOINTMENT src);

// JUDGE
bool CompareAppt(APPOINTMENT a, APPOINTMENT b);

/*    useful   */
bool CheckConflict(APPOINTMENT a, APPOINTMENT b);

// DISPLAY
void PrintAppt(APPOINTMENT appt);
/*    useful   */


// TODO: I/O
// 
// load
// save
APPOINTMENT LoadApptFromDisk(FILE* fp);
void saveApptToDisk(APPOINTMENT appt, FILE* fp);


// get set
int GetApptId(APPOINTMENT appt);

//void SetApptId(APPOINTMENT* appt, int id);

void GetApptTitle(APPOINTMENT appt, char* title);

void SetApptTitle(APPOINTMENT* appt, char* title);

struct tm GetApptStartTime(APPOINTMENT appt);

void SetApptStartTime(APPOINTMENT* appt, struct tm start_time);

int GetApptDuration(APPOINTMENT appt);

void SetApptDuration(APPOINTMENT* appt, int duration_minutes);



void GetApptLocation(APPOINTMENT appt, char* location);

void SetApptLocation(APPOINTMENT* appt, char* location);

void GetApptDescription(APPOINTMENT appt, char* description);

void SetApptDescription(APPOINTMENT* appt, char* description);

STATUS_ENUM GetApptStatus(APPOINTMENT appt);

void SetApptStatus(APPOINTMENT* appt, STATUS_ENUM status);


//void DestroyAppointment(APPOINTMENT* appt);
