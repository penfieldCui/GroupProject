//impl of appt day
// program71985 - fall23
// zongping cui
#include "day.h"
#include <stdlib.h>


DAY* InitialD(int day, int month, int year) {
	DAY* d = (DAY*)malloc(sizeof(DAY));
	if (d == NULL) {
		fprintf(stderr, "error allocating memory for DAY\n");
		return NULL;
	}
	d->day = day;
	d->month = month;
	d->year = year;
	return d;
}

//void PrintDay(DAY* d) {
//
//}

//bool CopyDay(DAY* dest, DAY* src) {
//	return true;
//}
//
//bool CompareDay(DAY* a, DAY* b) {
//
//	return true;
//}

int GetDay(DAY* d) {
	return d->day;
}

int GetMonth(DAY* d) {
	return d->month;
}

int GetYear(DAY* d) {
	return d->year;
}

void DestroyDay(DAY* d) {
	if (d != NULL) {


		DestroyList(&(d->appts));

		free(d);
	}
		
}


//bool SetDay(DAY* d, int day) {
//	if (d == NULL) {
//		fprintf(stderr, "NULL pointer: DAY\n");
//		return false;
//	}
//	d->day = day;
//	return true;
//}
//
//bool SetMonth(DAY* d, int);
//
//bool SetYear(DAY* d, int);