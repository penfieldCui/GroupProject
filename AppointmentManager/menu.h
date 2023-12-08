#pragma once

#include"appointment.h"
#include"day.h"
#include<stdbool.h>



#define MAXMENUREAD	5

/*    useful   */
// user input date, convert and return value to struct tm
bool ChooseADay(struct tm* time);
/*    useful   */

bool subMenu_edit(APPOINTMENT* a);

void subMenu_appointment_display(DAY* day[]);

void subMenu_search(DAY* day[]);

void Menu(DAY* day[]);



//void ReadInput();