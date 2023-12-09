// list interface
// czp
// program71985 - fall23
#pragma once

#include "appointment.h"
#include <stdbool.h>




typedef struct listNode {
	APPOINTMENT data;
	struct listNode* next;
}LISTNODE, * PLISTNODE;


void Display(PLISTNODE list);

bool Check(PLISTNODE* list, APPOINTMENT i);

bool Add(PLISTNODE* list, APPOINTMENT i);

bool Remove(PLISTNODE* list, APPOINTMENT i);

//PLISTNODE Search(PLISTNODE list, APPOINTMENT i);

//PLISTNODE SearchR(PLISTNODE list, APPOINTMENT i);

// SEARCH
PLISTNODE SearchApptInListById(PLISTNODE list, int id);

int GetCountList(PLISTNODE list);

void DestroyList(PLISTNODE* list);

bool SaveListToDisk(PLISTNODE list, FILE* fp);