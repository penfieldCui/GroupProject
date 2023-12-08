#include "menu.h"
#include "Calendar.h"
#include <stdio.h>

#define NUMMONTHDISPLAY 2

#define SAVEFILE "savefile.dat"


//int main(void) {
//	DAY* days[DAYLIMIT] = { NULL };  // REMEMBER to initial with NULL
//	LoadAllDays(days, SAVEFILE);
//	int numOfDay = GetNumOfDays(days, DAYLIMIT);
//	int x;
//}

int main(void) {
//int test(void) {


	printf("start\n");
	struct tm* local_time = GetCurrentTime();
	
	/****    load data   ****/
	DAY* days[DAYLIMIT] = {NULL};  // REMEMBER to initial with NULL
	//1111 loadAllDays

	


	/*    23:16    */  
	// fake data
	/*days[0] = InitialD(30, 12, 2023);

	days[1] = InitialD(31, 12, 2023);
	days[2] = InitialD(2, 12, 2023);
	days[3] = InitialD(7, 12, 2023);
	days[4] = InitialD(11, 1, 2024);
	days[5] = InitialD(6, 1, 2024);
	days[6] = InitialD(3, 2, 2024);
	days[7] = InitialD(22, 2, 2024);
	days[8] = InitialD(29, 1, 2024);
	days[9] = InitialD(1, 12, 2023);
	APPOINTMENT a1 = CreateAppt(23120701, "idk\0", *local_time, 30, "\0", "\0", 1);
	APPOINTMENT a2 = CreateAppt(23120702, "idk\0", *local_time, 30, "\0", "\0", 2);
	APPOINTMENT a3 = CreateAppt(23120703, "idk\0", *local_time, 30, "\0", "\0", 3);*/
	APPOINTMENT a4 = CreateAppt(23120704, "idk\0", *local_time, 30, "\0", "\0", 0);
	/*     23:16   */

	LoadAllDays(days, SAVEFILE);
	int numOfDay = GetNumOfDays(days, DAYLIMIT);
	
	//int index = SearchDayInArrayByDate(days, DAYLIMIT, *local_time);
	//->tm_mon + 1, local_time->tm_year + 1900
	PrintMonths(days, NUMMONTHDISPLAY, *local_time);

	/*     23:16   */
	//AddApptToDay(days[9], a1);
	//AddApptToDay(days[9], a2);
	//AddApptToDay(days[9], a3);

	//AddApptToDay(days[9], a4);
	PrintDay(days[0]);
	PrintDay(days[9]);
	SearchApptById(days, GetCapacity(), 23120704);
	//RemoveApptFromDay(days[9], a3);
	// test function£¬ generate by today for test only
	//int newId = GenerateUidOfAppt(days, GetCapacity(), *local_time); 
	/*     23:16   */

	/****    run menu   ****/
	//Menu(days);



	/****    end   ****/
	APPOINTMENT* tmpAppt;
	if (tmpAppt = SearchApptById(days, GetCapacity(), 30122303)) {
		PrintAppt(*tmpAppt);
	}
	else {
		printf("NOT found\n");
	}
	SaveAllDays(days, numOfDay, SAVEFILE);

	DestroyAllDay(days);

	printf("exit\n");
	return 0;
}