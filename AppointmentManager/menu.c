#include "menu.h"
#include "StreamIO.h"
#include "Calendar.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



//
bool ChooseADay(struct tm* time) {
	char date_str[MAXSIZE];
	bool is_valid = false;
	bool is_formatted = false;
	int day = -1, month = -1, year = -1;
	do {
		printf("please enter a date in format dd-MM-yyyy or dd-MM: \n");
		if (ReadStream(date_str, MAXSIZE, stdin) == NOTREAD)
			printf("WARN: read failed, please retry\n");
		else {
			// convert to time
			if (sscanf(date_str, "%d-%d-%d", &day, &month, &year) == 3) {
				is_valid = IsValidDate(day, month, year);
			}
			else if (sscanf(date_str, "%d-%d", &day, &month) == 2) {
				struct tm* local_time = GetCurrentTime();
				year = local_time->tm_year + 1900;
				is_valid = IsValidDate(day, month, year);
			}
		}

		if (is_valid) {
			time->tm_mday = day;
			time->tm_mon = month - 1;
			time->tm_year = year - 1900;
			is_formatted = true;
		}
		else {
			printf("WARN: error formating %d-%d-%d, please retry\n", day, month, year);
		}

	} while (!is_formatted);

	//strftime(date_str, MAXSIZE, "\n%Y-%m-%d %H:%M\n", time);
	//printf(date_str);


	return is_formatted;
}

// test 00:44
//int main(void) {
//	struct tm* local_time = GetCurrentTime();
//	ChooseADay(local_time);
//
//	char date_str[MAXSIZE];
//	strftime(date_str, MAXSIZE, "\n%Y-%m-%d %H:%M\n", local_time);
//	printf(date_str);
//}


//fgets
char selectOption() {
	char letterChoice[MAXMENUREAD];
	// 11 30
	if (ReadStream(letterChoice, MAXMENUREAD, stdin) == NOTREAD) {
		letterChoice[0] = '\0';
	}
	return letterChoice[0];
}

//subMenu for update appointment
bool subMenu_edit(APPOINTMENT* a) {
	char choice_edit;
	do {
		printf("\n  **** EDIT ****\n\n");
		printf("a) Start Time\n");
		printf("b) Duration\n");
		printf("c) Location\n");
		printf("d) Description\n");
		printf("e) Go back\n");

		printf("Enter your choice: ");
		


		switch (choice_edit = selectOption()) {
		case'a':
			//start time 
			break;
		case'b':
			//duration
			break;
		case'c':
			//location
			break;
		case'd':
			//description
			break;
		case'e':
			//exit
			break;
		default:
			printf("!!! WARN: Invalid choice. Please try again.\n");
		}
	} while (choice_edit != 'e');

	return true;
}

//subMenu for display appointment
void subMenu_appointment_display(DAY* day) {
	char choice_day;
	do {
		printf("\n  **** DISPLAY ****\n\n");
		printf("a) Appointments in a day\n");
		printf("b) All appointments\n");
		printf("c) Exit and go back\n");

		printf("Enter your choice: ");
		

		switch (choice_day = selectOption()) {
		case'a':
			//list of appointment in 1 day
			break;
		case'b':
			//list of all appointments
			break;
		case'c':
			//exit
			break;
		default:
			printf("!!! WARN: Invalid choice. Please try again.\n");
		}
	} while (choice_day != 'c');
}
//subMenu for search appointment
void subMenu_search(DAY* day) {
	char choice_search;
	
	do {
		printf("\n  **** SEARCH ****\n\n");
		printf("a) search by title\n");
		printf("b) search by id\n");
		printf("c) search by status (expired/not expired)\n");
		printf("d) search by time\n");
		printf("e) Go back\n");

		printf("Enter your choice: ");
		/*scanf("%c", &choice_search);*/


		switch (choice_search = selectOption()) {
		case'a':
			//search by title 
			break;
		case'b':
			//search by Id
			break;
		case'c':
			//search by status
			break;
		case'd':
			//search by time
			break;
		case'e':
			//exit
			break;
		default:
			printf("!!! WARN: Invalid choice. Please try again.\n");
		}
	} while (choice_search != 'e');
}


// main menu
void Menu(DAY* day) {
	printf(" ********************************** \n");
	printf("**        Welcome to\n");
	printf("**   AppointmentManger\n\n");
	char choice;
	do {
		//display menu
		printf("\n  **** MAIN ****\n\n");
		//add in do - while loop  --for return NULL
		printf("a) Add Appointment\n"); 
		printf("b) Update appointment\n"); 
		printf("c) Delete an appointment\n"); 
		printf("d) Free a day\n"); 
		printf("e) Display\n"); 
		printf("f) Search\n"); 
		printf("g) Exit\n");

		printf("Enter your Choice: ");
		/*scanf("%c", &choice);*/

		switch (choice = selectOption()) {
		case'a':
			//add appointment function
			break;
		case'b':
			//input and display of choosen day
			subMenu_edit(NULL);  //ADD the menu  - TODO put appointment instead of NULL
			//Updating appointment
			break;
		case'c':
			//Delete appointment function
			break;
		case'd': 
			//free a day function
			break;
		case'e':
			//Display submenu
			subMenu_appointment_display(day); 
			break;
		case'f':
			//display menu search
			subMenu_search(day); 
			break;
		case'g':
			//exit
			break;
		default:
			printf("!!! WARN: Invalid choice. Please try again.\n");
		}
	} while (choice != 'g');
}

//void Menu() {
//}
//void Menu(DAY* day) {
//
//	printf(" ********************************** \n");
//	printf("**        Welcome to\n");
//	printf("**   AppointmentManger\n");
//
//	do {
//
//		
//		printf("** a) Show number of empty seats\n");  // select, count
//		printf("** b) Show list of empty seats\n");  // select *
//		printf("** c) Show alphabetical list(by passenger name) of seats\n"); // select,reorder
//
//		scanf
//
//		switch (letterChoice[0])
//		{
//		case 'a':
//			//Show number of empty seats
//			printf("\n- Number of empty seat in Flight %d : %d\n", flight_number, numOfEmptySeat);
//			break;
//		case 'b':  // update
//
//			scanf
//				//display list of appt in choosen day  //TODO
//
//				return PLISTNODE
//
//			subMenu_update(APPTOINTMENT* appt);
//
//			break;
//
//
//		case 'e':  // display
//			void subMenu_display(DAY * day);
//			break;
//		default:
//			printf_s("Invalid value entered.\n");
//			break;
//		}
//
//	} while (1);
//
//}

