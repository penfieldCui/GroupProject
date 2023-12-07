#include "menu.h"

#include <stdio.h>

//not yet DEC 5th

int main(void) {
	//load
	printf("start\n");

	time_t current_time;
	time(&current_time);

	// Convert to local time format
	struct tm* local_time = localtime(&current_time);

	DAY* d = InitialD(30,12,2023);
	APPOINTMENT a = CreateAppt(30122301, "idk\0", *local_time, 30, "\0", "\0");

	

	AddApptToDay(d, a);
	AddApptToDay(d, a);
	AddApptToDay(d, a);

	AddApptToDay(d, a);

	PrintDay(d);
	printf("--");

	RemoveApptFromDay(d, a);
	RemoveApptFromDay(d, a);
	RemoveApptFromDay(d, a);
	PrintDay(d);
	DestroyDay(d);


	Menu(NULL);

	printf("exit\n");
	//save
	return 0;
}