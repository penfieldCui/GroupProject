//impl of appt day
// program71985 - fall23
// zongping cui
#include "day.h"
#include <stdlib.h>

DAY CreateEmptyD(int day, int month, int year) {
	DAY d;
	d.appts = NULL;
	d.day = day;
	d.month = month;
	d.year = year;
	return d;
}

DAY* InitialD(int day, int month, int year) {
	DAY* d = (DAY*)malloc(sizeof(DAY));
	if (d == NULL) {
		fprintf(stderr, "error allocating memory for DAY\n");
		return NULL;
	}
	d->appts = NULL;
	d->day = day;
	d->month = month;
	d->year = year;
	return d;
}

//judge
bool CompareDay(DAY* a, DAY b) {
	if (a == NULL) {
		return false;
	}

	if (a->day == b.day && a->month == b.month && a->year == b.year) {
		return true; // same day
	}

	return false;  //they not same
}

// list operation
bool AddApptToDay(DAY* d, APPOINTMENT appt) {
	if (d == NULL) {
		fprintf(stderr, "NULL pointer: DAY\n");
		return false;
	}
	return Add(&(d->appts), appt);
}

bool RemoveApptFromDay(DAY* d, APPOINTMENT appt) {
	return Remove(&(d->appts), appt);
}

void PrintDay(DAY* d) {
	printf("%02d/%02d/%d :{\n",GetDay(d), GetMonth(d), GetYear(d));
	Display(d->appts);
	printf("}");
}

//bool CopyDay(DAY* dest, DAY* src) {
//	return true;
//}
//
//bool CompareDay(DAY* a, DAY* b) {
//
//	return true;
//}

//void PrintDay(DAY* d) {
//	
//
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