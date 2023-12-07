//Chris - 7th December

#pragma once

#include"appointment.h"
#include"day.h"
#include<stdbool.h>

bool subMenu_edit(APPOINTMENT* a);

void subMenu_appointment_display(DAY* day);

void subMenu_search(DAY* day);

void Menu(DAY* day);



//void ReadInput();