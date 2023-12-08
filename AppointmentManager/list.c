#include "list.h"
#include "appointment.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//list impl
// czp NOV 14

void Display(PLISTNODE list) {
	PLISTNODE current = list;
	if (current == NULL) // link empty
		return;
	
	do {
		PrintAppt(current->data);
		current = current->next;
	} while (current != NULL);
}

bool Add(PLISTNODE* list, APPOINTMENT i) {
	PLISTNODE newNode = (PLISTNODE)malloc(sizeof(LISTNODE));
	/***********************************************************************/
	assert(newNode != NULL); //  quick and dirty !!!!!!!!!!!!!!!!

	if (!CopyAppt(&(newNode->data), i)) {
		free(newNode);
		return false;
	}
	newNode->next = *list;
	*list = newNode;

	return true;
}

bool Remove(PLISTNODE* list, APPOINTMENT i) {
	//if (*list == NULL)    /*  not sure */   //case 0 list empty   nth to remove
	//	return;

	PLISTNODE current = *list;

	// not empty, match first/head item			after that current seems never be NULL
	if (current != NULL && CompareAppt(current->data, i)) {
		
		if (current->next == NULL) // case 1 current is the only item
			*list = NULL;
		else					// case 2 there is second item
			*list = current->next; 
		free(current);
		return true;
	}

	// not empty, head not mach
	//PLISTNODE prev = NULL;
	PLISTNODE prev = NULL;
	
	while (current != NULL && !CompareAppt(current->data, i)) {   //
		prev = current;
		current = current->next;
	}

	if (current == NULL)  // not found
		return false;
	
	if (prev == NULL) {
		return false;
	}
	prev->next = current->next;
	
	/*do {

	} while ();*/
	return true;
}

int GetCountList(PLISTNODE list) {
	int count = 0;
	PLISTNODE current = list;
	while (current != NULL) {
		count++;
		current = current->next;
	}
	return count;
}

//PLISTNODE Search(PLISTNODE list, APPOINTMENT i){
//	PLISTNODE current = list;
//
//	while (current != NULL) {
//		if (CompareItems(current->data, i))
//			return current;  // 
//
//		current = current->next;
//	}
//	
//	return (PLISTNODE)NULL;
//}
//
//PLISTNODE SearchR(PLISTNODE list, APPOINTMENT i) {
//	PLISTNODE current = list;
//
//	if (current == NULL) // 2 cases
//		return (PLISTNODE)NULL;
//
//	else
//		if (CompareItems(current->data, i))
//			return current;
//		else
//			return SearchR(current->next, i);
//	
//}



// pretty like   clear() in cpp
void DestroyList(PLISTNODE* list) {

	PLISTNODE current = *list;
	while (current != NULL) {
		PLISTNODE tmp = current;
		current = current->next;
		DestroyAppt(&(tmp->data));
		free(tmp);
	}
	*list = NULL;  //its better
}

bool SaveListToDisk(PLISTNODE list, FILE* fp) {
	PLISTNODE current = list;
	while (current != NULL) {
		saveApptToDisk(current->data, fp);
		current = current->next;
	}
	return true;
}