/**
 * José Gómez
 * Víctor Huerta
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_HEAP 20

typedef struct {
	int arr[MAX_HEAP];
	int size;
} HEAP;

#define parent(n) ((n-1)/2)
#define left(n) (n*2+1)
#define right(n) (n*2+2)
#define EMPTY -1

void swap(int *a,int *b);
void heap_init(HEAP *heap);
void heap_offer(HEAP *heap,int num);
int heap_poll(HEAP *heap);

int main()
{
    srand(time(NULL));

    HEAP h1;
    heap_init(&h1);

    int rand_number;
    for (int i = 0; i < 20; i++)
    {
        rand_number = rand() % 50; // Rango entre 0 y 50, mientras el tamaño del arreglo es de 20
        heap_offer(&h1, rand_number);
    }
    
	for(int i=0;i<13;i++)
    {
		printf("%d ",h1.arr[i]);
    }

	printf("\nRetirar elementos: \n");
	int poll;
	while((poll=heap_poll(&h1))!=EMPTY)
	{
		printf("%d ",poll);
	}
    
}

void heap_offer(HEAP *heap, int n)
{
    int elem = heap->size;

    heap->arr[elem] = n;
    heap->size = heap->size + 1;

    while(elem > 0 && heap->arr[elem] < heap->arr[parent(elem)])
    {
        swap(&(heap->arr[elem]),&(heap->arr[parent(elem)]));
        elem = parent(elem);
    }

}

void heap_init(HEAP *heap)
{
    heap->size = 0;
}

int heap_poll(HEAP *heap)
{
	int retval;
	int last,elem,min;
	if(heap->size==0)
		retval = EMPTY;
	else
	{
		retval = heap->arr[0];
		heap->size--;
		last = heap->size;

		heap->arr[0] = heap->arr[last];
		elem=0;
		while(left(elem)<heap->size)
		{
			min = left(elem);

			if(right(elem) < heap->size && heap->arr[right(elem)] < heap->arr[left(elem)])
				min = right(elem);

			if(heap->arr[elem] > heap->arr[min])
				swap(&heap->arr[elem], 	&heap->arr[min]);

			elem = min;
		}

	}

	return retval;
}

void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}