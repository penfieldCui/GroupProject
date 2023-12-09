// menu ADT Header
// 
//Zongping Cui - Chris Mitskas - prog71985 - fall23 - Group 5: Group Project Assignment
#pragma once

#include"appointment.h"
#include"day.h"
#include<stdbool.h>



#define MAXMENUREAD	5
#define MAXRETRY 3
#define NUMMONTHDISPLAY 2

/*    useful   */
// user input date, convert and return value to struct tm
bool ChooseADay(struct tm* time);

// ret true as y or Y
// false as n or N or not recognize
bool ChooseYorN();
/*    useful   */

bool subMenu_edit(DAY* days[], APPOINTMENT* a);

void subMenu_appointment_display(DAY* day[]);

void subMenu_search(DAY* day[]);

void Menu(DAY* day[]);



//void ReadInput();