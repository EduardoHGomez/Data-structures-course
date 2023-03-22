/*
 * queue.h
 *
 *  Created on: 17 mar 2023
 *      Author: jluis
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "datatypes.h"

struct STR_QUEUE_NODE {
	TYPE elem;
	struct STR_QUEUE_NODE *next;
};

struct STR_QUEUE {
	struct STR_QUEUE_NODE *front,*rear;
	int size;
};

typedef struct STR_QUEUE * QUEUE;

QUEUE queue_create();
void queue_offer(QUEUE q,TYPE e);
BOOL queue_empty(QUEUE q);
TYPE queue_poll(QUEUE q);
TYPE queue_peek(QUEUE q);
void queue_destroy(QUEUE q);


#endif /* QUEUE_H_ */
