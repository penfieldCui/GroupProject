#pragma once

#include "appointment.h"
#include <stdbool.h>


// list interface
// czp

typedef struct listNode {
	APPOINTMENT data;
	struct listNode* next;
}LISTNODE, * PLISTNODE;


void Display(PLISTNODE list);

bool Add(PLISTNODE* list, APPOINTMENT i);

bool Remove(PLISTNODE* list, APPOINTMENT i);

//PLISTNODE Search(PLISTNODE list, APPOINTMENT i);

//PLISTNODE SearchR(PLISTNODE list, APPOINTMENT i);


void DestroyList(PLISTNODE* list);