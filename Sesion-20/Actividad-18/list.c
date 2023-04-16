/*
 * list.c
 *
 *  Created on: 24 mar. 2023
 *      Author: jluis
 */
#include "list.h"

LIST list_create()
{
	LIST new = malloc(sizeof(struct STR_LIST));
	new->first = NULL;
	new->last = NULL;
	new->size = 0;
	return new;
}

void list_add(LIST l,TYPE e)
{
	struct STR_LIST_NODE *new = malloc(sizeof(struct STR_LIST_NODE));
	new->elem = e;
	new->prior = NULL;
	new->next = NULL;

	if(l->first == NULL)	// �La lista est� vac�a?
		l->first = new;
	else
		l->last->next = new;

	new->prior = l->last;
	l->last = new;
	l->size++;
}

int list_size(LIST l)
{
	return(l->size);
}

TYPE list_get(LIST l,int pos)
{
	struct STR_LIST_NODE *ptr = l->first;
	int i;

	for(i=0;i<pos;i++)
		ptr = ptr->next;

	return(ptr->elem);
}

void list_destroy(LIST l)
{
	struct STR_LIST_NODE *ptr, *toremove;

	ptr = l->first;

	while(ptr!=NULL)
	{
		toremove = ptr;
		ptr = ptr->next;
		free(toremove);
	}
	free(l);
}
