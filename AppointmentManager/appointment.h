#pragma once

#include <time.h>
#include <stdbool.h>

#define MAXSIZE 80
#define MAXTEXT 255

typedef struct appointment {

	int id;

	char title[MAXSIZE];

	char date[11]; // format: yyyy-MM-dd
	char time[6];  // format: hh:mm

	struct tm start_time; // use struct tm to represent start time
	int duration_minutes; // duration minutes

	char location[MAXSIZE];
	char description[MAXTEXT];


}APPOINTMENT;


bool checkConflict(APPOINTMENT a, APPOINTMENT b);

//C
void createAppointment(APPOINTMENT a);


//R


//U


//D


