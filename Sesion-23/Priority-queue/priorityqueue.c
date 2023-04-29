#include <stdio.h>
#include "priorityqueue.h"

void swap(TYPE *a,TYPE *b)
{
	TYPE temp = *a;
	*a = *b;
	*b = temp;
}

PRIORITYQUEUE priorityqueue_create(int max_size,COMPAREFUNC cf,PRINTFUNC pf)
{
	PRIORITYQUEUE newpq = malloc(sizeof(struct STRPRIORITYQUEUE));
	int i;
	newpq->arr = malloc(max_size * sizeof(TYPE));
	newpq->max_size = max_size;
	// Inicializar todos los elementos del arreglo con NULL
	for(i=0;i<max_size;i++)
		newpq->arr[i] = NULL;

	newpq->size = 0;
	newpq->cf = cf;
	newpq->pf = pf;

	return newpq;
}

void priorityqueue_offer(PRIORITYQUEUE pq,TYPE data)
{
	int idx = pq->size;


	pq->arr[idx] = data;
	pq->size = pq->size + 1;

	while(idx>0 && pq->cf(pq->arr[idx],pq->arr[parent(idx)])<0)
	{
		swap(&(pq->arr[idx]),&(pq->arr[parent(idx)]));
		idx = parent(idx);
	}
}

TYPE priorityqueue_poll(PRIORITYQUEUE pq)
{
	TYPE retval;
	int ilast,ielem,imin;
	if(pq->size==0)
		retval = NULL;
	else
	{
		retval = pq->arr[0];
		pq->size--;
		ilast = pq->size;

		// Poner el último elemento al principio
		pq->arr[0] = pq->arr[ilast];
		ielem=0;
		while(left(ielem)<pq->size) // Mientras tenga hijo izquierdo
		{
			imin = left(ielem);

			// Tiene hijo derecho y ademas el hijo derecho
			// es más pequeño que el izquierdo

			if(right(ielem) < pq->size && pq->cf(pq->arr[right(ielem)],pq->arr[left(ielem)])<1)
				imin = right(ielem);


			if(pq->cf(pq->arr[ielem],pq->arr[imin])>0)
				swap(&pq->arr[ielem],&pq->arr[imin]);

			ielem = imin;
		}

	}
	return retval;
}

// Tarea
TYPE priority_peek(PRIORITYQUEUE pq)
{
    return pq->arr[0];
}

int priority_size(PRIORITYQUEUE pq)
{
    return pq->size;
}

BOOL priorityqueue_isempty(PRIORITYQUEUE pq)
{
    if (priority_peek(pq) == NULL)
    {
        return 1;
    }

    return 0;
    
}