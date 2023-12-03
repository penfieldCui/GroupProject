#include "list.h"
#include "item.h"
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
		PrintItem(current->data);
		current = current->next;
	} while (current != NULL);
}

void Add(PLISTNODE* list, ITEM i) {
	PLISTNODE newnode = (PLISTNODE)malloc(sizeof(LISTNODE));
	/***********************************************************************/
	assert(newnode != NULL); //  quick and dirty !!!!!!!!!!!!!!!!

	newnode->data = CopyItem(i);
	newnode->next = *list;
	*list = newnode;

}

void Remove(PLISTNODE* list, ITEM i) {
	//if (*list == NULL)    /*  not sure */   //case 0 list empty   nth to remove
	//	return;

	PLISTNODE current = *list;

	// not empty, match first/head item			after that current seems never be NULL
	if (current != NULL && CompareItems(current->data, i)) {
		
		if (current->next == NULL) // case 1 current is the only item
			*list = NULL;
		else					// case 2 there is second item
			*list = current->next; 
		free(current);
		return;
	}

	// not empty, head not mach
	//PLISTNODE prev = NULL;
	PLISTNODE prev = NULL;
	
	while (current != NULL && !CompareItems(current->data, i)) {   //
		prev = current;
		current = current->next;
	}

	if (current == NULL)  // not found
		return;
	
	prev->next = current->next;
	
	/*do {

	} while ();*/

}


PLISTNODE Search(PLISTNODE list, ITEM i){
	PLISTNODE current = list;

	while (current != NULL) {
		if (CompareItems(current->data, i))
			return current;  // 

		current = current->next;
	}
	
	return (PLISTNODE)NULL;
}

PLISTNODE SearchR(PLISTNODE list, ITEM i) {
	PLISTNODE current = list;

	if (current == NULL) // 2 cases
		return (PLISTNODE)NULL;

	else
		if (CompareItems(current->data, i))
			return current;
		else
			return SearchR(current->next, i);
	
}



// pretty like   clear() in cpp
void DestroyList(PLISTNODE* list) {

	PLISTNODE current = *list;
	while (current != NULL) {
		PLISTNODE tmp = current;
		current = current->next;
		DestroyItem(tmp->data);
		free(tmp);
	}
	*list = NULL;  //its better
}
