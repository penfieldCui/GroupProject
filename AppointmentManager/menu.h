#pragma once

#include"appointment.h"
#include"day.h"
#include<stdbool.h>



#define MAXMENUREAD	5

bool ChooseADay(struct tm* time);

bool subMenu_edit(APPOINTMENT* a);

void subMenu_appointment_display(DAY* day);

void subMenu_search(DAY* day);

void Menu(DAY* day);



//void ReadInput();