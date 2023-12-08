#include "menu.h"
#include "Calendar.h"
#include <stdio.h>


#define DAYLIMIT 100  //don't care about appointment more than 3 months
#define SAVEFILE "savefile.dat"

//int test(void) {
int main(void) {
	//load
	printf("start\n");

	time_t current_time;
	time(&current_time);

	// Convert to local time format
	struct tm* local_time = localtime(&current_time); // to expired some appointments when load


	DAY* days[DAYLIMIT] = {NULL};

	days[0] = InitialD(30, 12, 2023);

	days[1] = InitialD(31, 12, 2023);
	days[2] = InitialD(2, 12, 2023);
	days[3] = InitialD(7, 12, 2023);
	days[4] = InitialD(3, 11, 2023);
	days[5] = InitialD(6, 1, 2023);

	int numOfDay = GetNumOfDays(days, DAYLIMIT);
	
	APPOINTMENT a = CreateAppt(30122301, "idk\0", *local_time, 30, "\0", "\0");

	int index = SearchDayInArray(days, DAYLIMIT, *local_time);


	AddApptToDay(days[0], a);
	AddApptToDay(days[1], a);
	AddApptToDay(days[4], a);

	AddApptToDay(days[0], a);

	saveDaysToDisk(days, numOfDay, SAVEFILE);

	PrintDay(days[0]);
	printf("--");




	RemoveApptFromDay(days[0], a);
	RemoveApptFromDay(days[0], a);
	RemoveApptFromDay(days[0], a);
	PrintDay(days[0]);
	DestroyDay(days[0]);


	//Menu(days);

	printf("exit\n");
	//save
	return 0;
}