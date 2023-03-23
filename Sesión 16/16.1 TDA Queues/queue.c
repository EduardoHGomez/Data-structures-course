/*
 * queue.c
 *
 *  Created on: 17 mar 2023
 *      Author: jluis
 */
#include "queue.h"
#include <stdlib.h>

#include <stdio.h>

QUEUE queue_create()
{
	QUEUE new = malloc(sizeof(struct STR_QUEUE));

	new->front = NULL;
	new->rear = NULL;
	new->size = 0;

	return(new);
}

void queue_offer(QUEUE q, TYPE e)
{
	struct STR_QUEUE_NODE *new_node = malloc(sizeof(struct STR_QUEUE_NODE));
	new_node->elem = e;
	new_node->next = NULL;

	if (q->front == NULL)
	{
		q->front = new_node;
		q->rear = new_node;
	}
	else
	{
		q->rear->next = new_node;
		q->rear = new_node;
	}
	
	q->size++;

}

BOOL queue_empty(QUEUE q)
{
	if (q->front == NULL)
		return 1;
	else
		return 0;
}

TYPE queue_poll(QUEUE q)
{
	struct STR_QUEUE_NODE *toremove = q->front;
	TYPE elem = q->front->elem;

	q->front = q->front->next;
	
	free(toremove);

	return elem;
}

TYPE queue_peek(QUEUE q)
{
	if (q->front == NULL)
      return 0;
  	else
	    return q->front->elem;
}

void queue_destroy(QUEUE q)
{
	while(!queue_empty(q))
		queue_poll(q);
	free(q);
}
