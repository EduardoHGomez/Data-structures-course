/*
 * queue.c
 *
 *  Created on: 17 mar 2023
 *      Author: jluis
 */
#include "queue.h"

QUEUE queue_create()
{
	QUEUE new = malloc(sizeof(struct STR_QUEUE));

	new->front = NULL;
	new->rear = NULL;
	new->size = 0;

	return(new);
}

void queue_offer(QUEUE q,TYPE e)
{
	/* Te toca implementar esta función */
}

BOOL queue_empty(QUEUE q)
{
	/* Te toca implementar esta función */
}

TYPE queue_poll(QUEUE q)
{
	/* Te toca implementar esta función */
}

TYPE queue_peek(QUEUE q)
{
	/* Te toca implementar esta función */
}

void queue_destroy(QUEUE q)
{
	while(!queue_empty(q))
		queue_poll(q);
	free(q);
}
