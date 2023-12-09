// all menu fuction

// program71985 - fall23
// zongping cui, chris
#include "menu.h"
#include "StreamIO.h"
#include "Calendar.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



//choose a fay function - user input
bool ChooseADay(struct tm* time) {
	char date_str[MAXSIZE];
	bool is_valid = false;
	bool is_formatted = false;
	int day = -1, month = -1, year = -1;
	do {
		//input date in 2 formats 1.day-month-year / 2.day-month
		printf("please enter a date in format dd-MM-yyyy or dd-MM: \n");
		if (ReadStream(date_str, MAXSIZE, stdin) == NOTREAD)
			printf("WARN: read failed, please retry\n");//failed to read
		else {
			// convert to time
			//day-month-year layout 
			if (sscanf(date_str, "%d-%d-%d", &day, &month, &year) == 3) {
				is_valid = IsValidDate(day, month, year);
			}
			//day-month layout 
			else if (sscanf(date_str, "%d-%d", &day, &month) == 2) {
				struct tm* local_time = GetCurrentTime();//input current time
				year = local_time->tm_year + 1900; //adjust year
				is_valid = IsValidDate(day, month, year);//confirm validation of date
			}
		}

		if (is_valid) {
			time->tm_mday = day; //adjust day
			time->tm_mon = month - 1; //adjust month
			time->tm_year = year - 1900;//adjsut the year 
			is_formatted = true;
		}
		else {

			printf("WARN: error formating %d-%d-%d, please retry\n", day, month, year);//if invalid print an error

		}

	} while (!is_formatted);

	//strftime(date_str, MAXSIZE, "\n%Y-%m-%d %H:%M\n", time);
	//printf(date_str);


	return is_formatted;
}

// 16:28
// ret true as y or Y
// false as n or N or not recognize
bool ChooseYorN() {
	char choice[MAXMENUREAD];
	int retry = 0;
	do {
		printf("Sure to proceed ?(y/n) \n");
		if (ReadStream(choice, MAXSIZE, stdin) == NOTREAD)
			printf("WARN: read failed, please retry\n");
		else {
			// convert to time
			char tmp = choice[0];
			if (tmp == 'y' || tmp == 'Y') {
				return true;
			}
			else if (tmp == 'n' || tmp == 'N') {
				return false;
			}
		}

		if (++retry > MAXRETRY) {
			printf("WARN: Retry limit exceeded, go back to previous level\n");
		}

	} while (retry <= MAXRETRY);
	return false; // just no
}

// test 00:44
//int main(void) {
//	struct tm* local_time = GetCurrentTime();
//	//ChooseADay(local_time);
//	if (ChooseYorN())
//		printf("yeah!");
//	else
//		printf("NOPE");
//	char date_str[MAXSIZE];
//	//strftime(date_str, MAXSIZE, "\n%Y-%m-%d %H:%M\n", local_time);
//	//printf(date_str);
//}


//fgets select an option on menus
char selectOption() {
	char letterChoice[MAXMENUREAD];
	// 11 30
	if (ReadStream(letterChoice, MAXMENUREAD, stdin) == NOTREAD) {
		letterChoice[0] = '\0';
	}
	return letterChoice[0];
}

//subMenu for update appointment-7th December - Chris
bool subMenu_edit(APPOINTMENT* a) {
	char choice_edit;
	do {
		//edit menu layout
		printf("\n  **** EDIT ****\n\n");
		printf("a) Start Time\n");
		printf("b) Duration\n");
		printf("c) Location\n");
		printf("d) Description\n");
		printf("e) Appointment status\n");
		printf("q) Go back\n");

		printf("Enter your choice: ");
		

		//switch cases for edit submenu
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
			//appointment_status
			break;
		case'q':
			//exit
			break;
		default:
			printf("!!! WARN: Invalid choice. Please try again.\n");//if invalid choice
		}
	} while (choice_edit != 'q');

	return true;
}

//subMenu for display appointment - 7th December - Chris
void subMenu_appointment_display(DAY* days[]) {
	char choice_day;
	do {
		//appointmnet display menu layout
		printf("\n  **** DISPLAY ****\n\n");
		printf("a) Appointments in a day\n");
		printf("b) All appointments\n");
		printf("q) Exit and go back\n");

		printf("Enter your choice: ");
		
		//switch cases 
		struct tm* time = GetCurrentTime();
		
		switch (choice_day = selectOption()) {
		case'a':

			//list of appointment in 1 day
			//PrintMonths(days, 1, *time);
			ChooseADay(time);
			int index = SearchDayInArrayByDate(days,GetCapacity(),*time);

			char time_str[MAXSIZE];

			//Dec 5   not sure
			strftime(time_str, MAXSIZE, "%Y-%m-%d", time);


			if (index == -1) {
				printf("No appointment in ");
				printf(time_str);
				printf("\n , please try another.\n\n");
			}
			else {
				PrintDay(days[index]);
			}
			break;
		case'b':
			//list of all appointments
			break;
		case'q':
			//exit
			break;
		default:
			printf("!!! WARN: Invalid choice. Please try again.\n"); //If invalid choice
		}
	} while (choice_day != 'q');
}

//subMenu for search appointment - 7th December - Chris
void subMenu_search(DAY* days[]) {

	char choice_search;
	
	do {
		//Menu layout
		printf("\n  **** SEARCH ****\n\n");
		printf("a) search by title\n");
		printf("b) search by id\n");
		printf("c) search by status (expired/not expired)\n");
		printf("d) search by time\n");
		printf("q) Go back\n");

		printf("Enter your choice: ");
		/*scanf("%c", &choice_search);*/


		//switch cases for search menu

		APPOINTMENT* tmpAppt;
		char buffer[MAXREAD];

		switch (choice_search = selectOption()) {
		case'a':
			//search by title
			break;
		case'b':



			//search by Id
			printf("\n- Enter id of a Appointment: ");
			ReadStream(buffer, MAXREAD, stdin);
			int id = atoi(buffer);
			if (tmpAppt = SearchApptById(days, GetCapacity(), id)) {
				printf("- Appointment found:\n  ");
				PrintAppt(*tmpAppt);
			}
			else {
				printf("!Appointment not found.\n");
			}

			break;
		case'c':
			//search by status
			break;
		case'd':
			//search by time
			break;
		case'q':
			//exit
			break;
		default:
			printf("!!! WARN: Invalid choice. Please try again.\n");//If Invalid choice
		}
	} while (choice_search != 'q');
}



// main menu - 7th December - Chris
void Menu(DAY* days[]) {
	printf(" ********************************** \n");
	printf("**        Welcome to\n");
	printf("**   AppointmentManger\n\n");
	char choice;
	do {
		printf("\n\n\n");
		struct tm time = *(GetCurrentTime());

		//display menu

		PrintMonths(days, 1, time);

		printf("  **** MAIN ****\n\n");
		//add in do - while loop  --for return NULL
		printf("a) Add Appointment\n"); 
		printf("b) Update appointment\n"); 
		printf("c) Delete an appointment\n"); 
		printf("d) Empty a day\n"); 
		printf("e) Display\n"); 
		printf("f) Search\n"); 
		printf("q) Exit\n");

		printf("Enter your Choice: ");
		/*scanf("%c", &choice);*/

		switch (choice = selectOption()) {
		case'a':
			//add appointment function
			printf("\n");
			if (!InputAndAddAppointmentToDay(days))
				printf("Add abort\n");



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
			subMenu_appointment_display(days);
			break;
		case'f':
			//display menu search
			subMenu_search(days);
			break;
		case'q':
			//exit
			break;
		default:
			printf("!!! WARN: Invalid choice. Please try again.\n");
		}
	} while (choice != 'q');
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

