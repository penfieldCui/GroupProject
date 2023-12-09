// day ADT implementation
// 
//Zongping Cui - Vinh Le - prog71985 - fall23 - Group 5: Group Project Assignment
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
		//printf("WARN: Access empty day - NULL pointer: DAY\n");
		return false;
	}

	if (a->day == b.day && a->month == b.month && a->year == b.year) {
		return true; // same day
	}

	return false;  //they not same
}

bool CheckConflict_Day(DAY* d, APPOINTMENT appt) {
	if (d->appts == NULL)
		return false;

	return Check(d->appts, appt);
}

// list operation
bool AddApptToDay(DAY* d, APPOINTMENT appt) {
	if (d == NULL) {
		printf("WARN: Access empty day - NULL pointer: DAY\n");
		return false;
	}
	return Add(&(d->appts), appt);
}

bool RemoveApptFromDay(DAY* d, APPOINTMENT appt) {
	if (d == NULL) {
		printf("WARN: Access empty day - NULL pointer: DAY\n");
		return false;
	}
	return Remove(&(d->appts), appt);
}

void PrintDay(DAY* d) {
	if (d == NULL) {
		printf("WARN: Access empty day - NULL pointer: DAY\n");
		return;
	}	
	printf("\nIn %02d/%02d/%d :{\n",GetDay(d), GetMonth(d), GetYear(d));
	Display(d->appts);
	printf("}\n\n");
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
		// clean the list
		DestroyList(&(d->appts));
		// free day
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



bool SaveAllDays(DAY* days[], int num, char* filename) {
	
	FILE* file = fopen(filename, "w");
	if (file == NULL) {
		printf("Error opening file.\n");
		return false;
	}

	fprintf(file, "Num of days: %d\n", num);

	for (int i = 0; i < num;i++) {
		fprintf(file, "Date: %d-", days[i]->day);
		fprintf(file, "%d-", days[i]->month);
		fprintf(file, "%d\n", days[i]->year);

		int count;
		count = GetCountList(days[i]->appts);
		fprintf(file, "Num of appts in that day: %d\n", count);

		SaveListToDisk(days[i]->appts, file);
	}

	fclose(file);
	return true;
}

// load days and put into array
bool LoadAllDays(DAY* days[], char* filename) {

	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		printf("Error opening file.\n");
		return false;
	}

	int numOfDays = 0;
	//int numConverted = fscanf(file, "Num of days: %d", &numOfDays);

	char line[MAXREAD];
	fgets(line, MAXREAD, file);
	int numConverted = sscanf(line, "Num of days: %d", &numOfDays);

	for (int i = 0; i < numOfDays; i++) {
		// if theres a day, initial one
		fgets(line, MAXREAD, file);
		int dd, mm, yy;
		numConverted = sscanf(line, "Date: %d-%d-%d", &dd, &mm, &yy);
		//numConverted = fscanf(file, "Date: %d-", &dd);
		//numConverted = fscanf(file, "%d-", &mm);
		//numConverted = fscanf(file, "%d", &yy);
		days[i] = InitialD(dd, mm, yy);

		// add appts to day
		int count;
		numConverted = fscanf(file, "Num of appts in that day: %d\n", &count);

		for (int j = 0; j < count;j++) {
			AddApptToDay(days[i], LoadApptFromDisk(file));
		}
	}

	/*fprintf(file, "Num of days: %d\n", num);   

	for (int i = 0; i < num;i++) {
		fprintf(file, "Date: %d-", days[i]->day);
		fprintf(file, "%d-", days[i]->month);
		fprintf(file, "%d\n", days[i]->year);

		int count;
		count = GetCountList(days[i]->appts);
		fprintf(file, "Num of appts in that day: %d\n", count);

		SaveListToDisk(days[i]->appts, file);
	}*/

	fclose(file);
	return true;
}

//int main(void) {
//	DAY* d = InitialD(10,5,2023);
//	saveDayToDisk(d,"data_file.dat");
//	
//
//	return 0;
//}
