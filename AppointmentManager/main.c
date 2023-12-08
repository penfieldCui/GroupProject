#include "menu.h"
#include "Calendar.h"
#include <stdio.h>

#define NUMMONTHDISPLAY 2

#define SAVEFILE "savefile.dat"


int test(void) {
//int main(void) {
	//load
	printf("start\n");

	struct tm* local_time = GetCurrentTime();
	
	// load
	DAY* days[DAYLIMIT] = {NULL};
	//loadAllDays


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
	APPOINTMENT a = CreateAppt(30122301, "idk\0", *local_time, 30, "\0", "\0");
	/*     23:16   */

	int numOfDay = GetNumOfDays(days, DAYLIMIT);
	
	//int index = SearchDayInArray(days, DAYLIMIT, *local_time);

	PrintMonths(days, NUMMONTHDISPLAY, local_time->tm_mon + 1, local_time->tm_year + 1900);

	/*     23:16   */
	AddApptToDay(days[0], a);
	AddApptToDay(days[1], a);
	AddApptToDay(days[4], a);

	AddApptToDay(days[0], a);
	PrintDay(days[0]);


	//Menu(days);



	/****    end   ****/
	
	SaveAllDays(days, numOfDay, SAVEFILE);

	DestroyAllDay(days);

	printf("exit\n");
	return 0;
}