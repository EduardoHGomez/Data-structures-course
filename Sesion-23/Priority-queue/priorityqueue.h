#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_

#include "datatypes.h"

#define parent(n) ((n-1)/2)
#define left(n) (n*2+1)
#define right(n) (n*2+2)

struct STRPRIORITYQUEUE {
	TYPE *arr;
	int max_size;
	int size;
	COMPAREFUNC cf;
	PRINTFUNC pf;
};

typedef struct STRPRIORITYQUEUE * PRIORITYQUEUE;

PRIORITYQUEUE priorityqueue_create(int max_size,COMPAREFUNC cf,PRINTFUNC pf);
void priorityqueue_offer(PRIORITYQUEUE pq,TYPE data);
TYPE priorityqueue_poll(PRIORITYQUEUE pq);
TYPE priorityqueue_peek(PRIORITYQUEUE pq);
int priorityqueue_size(PRIORITYQUEUE pq);
BOOL priorityqueue_isempty(PRIORITYQUEUE pq);

#endif /* PRIORITYQUEUE_H_ */
