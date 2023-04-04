/*
 * list.c
 *
 *  Created on: 24 mar. 2023
 *      Author: jluis
 */
#include "list.h"
#include <stdio.h>

LIST list_create()
{
	LIST new = malloc(sizeof(struct STR_LIST));
	new->prefirst = malloc(sizeof(struct STR_LIST_NODE));
	new->prefirst->prior = NULL;
	new->prefirst->elem = NULL;
	new->prefirst->next = NULL;
	new->first = NULL;
	new->last = NULL;
	new->postlast = malloc(sizeof(struct STR_LIST_NODE));;
	new->postlast->prior = NULL;
	new->postlast->elem = NULL;
	new->postlast->next = NULL;
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
	{
		l->first = new;
		l->prefirst->next = l->first;
	}
	else

		l->last->next = new;

	new->prior = l->last;

	l->last = new;
	l->postlast->prior = l->last;
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

//------TAREA---------
void list_remove(ITERATOR i, LIST l)
{
	struct STR_LIST_NODE *toremove = i; // Apuntar a donde está i
	
	// Condición apunta al inicio
	if (i->prior == NULL)
	{	
		l->first = i->next;
		l->first->prior = NULL;
		l->prefirst->next = l->first;
	}
	else if (i->next == NULL)
	{
		l->last = i->prior;
		l->last->next = NULL;
		l->postlast->prior = l->last;
	}
	else
	{
		i->prior->next = i->next;
		i->next->prior = i->prior;
	}

	l->size--;
	free(toremove);
}

void list_destroy(LIST l)
{
	struct STR_LIST_NODE *ptr, *toremove;

	ptr = l->prefirst;

	while(ptr!=NULL)
	{
		toremove = ptr;
		ptr = ptr->next;
		free(toremove);
	}
	free(l->postlast);
	free(l);
}

BOOL list_has_next(ITERATOR i)
{
	return(i->next!=NULL);
}

BOOL list_has_prior(ITERATOR i)
{
	return(i->prior!=NULL);
}

ITERATOR list_begin(LIST l)
{
	return(l->prefirst);
}

ITERATOR list_end(LIST l)
{
	return(l->postlast);
}

ITERATOR list_next(ITERATOR i) 
{
	return(i->next);
}

ITERATOR list_prior(ITERATOR i) 
{
	return(i->prior);
}