
#include "menu.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXMENUREAD	5

//fgets
char selectOption() {
	char letterChoice[MAXMENUREAD];


	// 11 30
	if (fgets(letterChoice, MAXMENUREAD, stdin) == NULL) {
		letterChoice[0] = '\0';
	}
	return letterChoice[0];
}




//subMenu for update appointment
bool subMenu_edit(APPOINTMENT* a) {
	char choice_edit;
	do {
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
			printf("Invalid choice. Please try again\n");
		}
	} while (choice_edit != 'e');
}

//subMenu for display appointment
void subMenu_appointment_display(DAY* day) {
	char choice_day;
	do {
		printf("a) Appointmnets in a day\n");
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
			printf("Invalid choice. Please try again\n");
		}
	} while (choice_day != 'c');
}
//subMenu for search appointment
void subMenu_search(DAY* day) {
	char choice_search;
	
	do {
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
			printf("Invalid choice. Please try again.\n");
		}
	} while (choice_search != 'e');
}


// main menu
void Menu(DAY* day) {
	char choice;
	do {
		//display menu
		printf(" ********************************** \n"); 
		printf("**        Welcome to\n"); 
		printf("**   AppointmentManger\n\n");
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
			printf("Invalid Input. Please try again.\n ");
		}
	} while (choice != 'g');
}

//int main(void) {
//	Menu(NULL);
//}

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
//	} while (ture);
//
//}

