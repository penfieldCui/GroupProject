#include "menu.h"
#include "Calendar.h"
#include <stdio.h>

#define NUMMONTHDISPLAY 2

#define SAVEFILE "savefile.dat"


//int test(void) {
int main(void) {

	printf("start\n");

	struct tm* local_time = GetCurrentTime();
	
	// load
	DAY* days[DAYLIMIT] = {NULL};
	//1111 loadAllDays

	//2222 check expired


	/*    23:16    */  
	// fake data
	days[0] = InitialD(30, 12, 2023);

	days[1] = InitialD(31, 12, 2023);
	days[2] = InitialD(2, 12, 2023);
	days[3] = InitialD(7, 12, 2023);
	days[4] = InitialD(11, 1, 2024);
	days[5] = InitialD(6, 1, 2024);
	days[6] = InitialD(3, 2, 2024);
	days[7] = InitialD(22, 2, 2024);
	days[8] = InitialD(29, 1, 2024);
	days[9] = InitialD(8, 12, 2023);
	APPOINTMENT a1 = CreateAppt(23120801, "idk\0", *local_time, 30, "\0", "\0");
	APPOINTMENT a2 = CreateAppt(23120802, "idk\0", *local_time, 30, "\0", "\0");
	APPOINTMENT a3 = CreateAppt(23120803, "idk\0", *local_time, 30, "\0", "\0");
	APPOINTMENT a4 = CreateAppt(23120804, "idk\0", *local_time, 30, "\0", "\0");
	/*     23:16   */

	int numOfDay = GetNumOfDays(days, DAYLIMIT);
	
	//int index = SearchDayInArray(days, DAYLIMIT, *local_time);

	PrintMonths(days, NUMMONTHDISPLAY, local_time->tm_mon + 1, local_time->tm_year + 1900);

	/*     23:16   */
	AddApptToDay(days[9], a1);
	AddApptToDay(days[9], a2);
	AddApptToDay(days[9], a3);

	AddApptToDay(days[9], a4);
	PrintDay(days[0]);
	PrintDay(days[9]);
	int newId = GenerateUidOfAppt(days, GetCapacity(), *local_time);

	/*     23:16   */

	//Menu(days);



	/****    end   ****/
	APPOINTMENT* tmpAppt;
	if (tmpAppt = SearchApptById(days, GetCapacity(), 30122303)) {
		PrintAppt(*tmpAppt);
	}
	else {
		printf("NOT fount\n");
	}
	SaveAllDays(days, numOfDay, SAVEFILE);

	DestroyAllDay(days);

	printf("exit\n");
	return 0;
}