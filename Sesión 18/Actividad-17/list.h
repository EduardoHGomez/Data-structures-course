/*
 * list.h
 *
 *  Created on: 24 mar. 2023
 *      Author: jluis
 */
#include "datatypes.h"

#ifndef LIST_H_
#define LIST_H_

struct STR_LIST_NODE {
	TYPE elem;
	struct STR_LIST_NODE *prior,*next;
};

typedef struct STR_LIST_NODE * ITERATOR;

struct STR_LIST {
	struct STR_LIST_NODE *prefirst,*first,*last,*postlast;
	int size;
};

typedef struct STR_LIST * LIST;

LIST list_create();
void list_add(LIST l,TYPE e);
int list_size(LIST l);
TYPE list_get(LIST l,int pos);
void list_destroy(LIST l);
BOOL list_has_next(ITERATOR i);
BOOL list_has_prior(ITERATOR i);
ITERATOR list_begin(LIST l);
ITERATOR list_end(LIST l);
ITERATOR list_next(ITERATOR i); 
ITERATOR list_prior(ITERATOR i);
void list_remove(ITERATOR i, LIST l); 

#endif /* LIST_H_ */
