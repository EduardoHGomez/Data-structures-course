/*
 * stack.c
 *
 *  Created on: 15 mar 2023
 *      Author: jluis
 */
#include "stack.h"

STACK stack_create()
{
	STACK new = malloc(sizeof(struct STR_STACK));

	new->top = NULL;
	new->size = 0;

	return(new);
}

void stack_push(STACK s,TYPE e)
{
	struct STR_STACK_NODE *new = malloc(sizeof(struct STR_STACK_NODE));

	new->elem = e;
	new->prev = s->top;
	s->top = new;
	s->size = s->size + 1;
}

BOOL stack_empty(STACK s)
{
	return(s->top==NULL);
}

TYPE stack_pop(STACK s)
{
	TYPE elem = NULL;
	struct STR_STACK_NODE *toremove;

	if(s->top!=NULL)
	{
		toremove = s->top;
		elem = s->top->elem;
		s->top = s->top->prev;
		s->size = s->size - 1;
		free(toremove);
	}

	return elem;
}

TYPE stack_peek(STACK s)
{
	TYPE toreturn=NULL;
	if(s->top!=NULL)
		toreturn = s->top->elem;
	return(toreturn);
}

void stack_destroy(STACK s)
{
	while(!stack_empty(s))
		stack_pop(s);
	free(s);
}
