#include <stdio.h>

#define MAX_HEAP 100

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

	HEAP h1;
	int arr[] = {22,13,15,17,8,26,29,5,14,19,2,7,20,13,29}; // Not working
	int nums[] = {10,12,5,7,9,19,6,8,17,23,29,2,5};
	int i,n;

	heap_init(&h1);

	for(i=0;i<13;i++)
		heap_offer(&h1,nums[i]);

	for(i=0;i<13;i++)
		printf("%d ",h1.arr[i]);

	printf("\nRetirando elementos del monti culo\n");
	i=0;
	while((n=heap_poll(&h1))!=EMPTY)
		printf("%d ",n);
}

void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heap_init(HEAP *heap)
{
	heap->size=0;
}

void heap_offer(HEAP *heap,int num)
{
	int elem = heap->size;


	heap->arr[elem] = num;
	heap->size = heap->size + 1;

	while(elem>0 && heap->arr[elem]<heap->arr[parent(elem)])
	{
		swap(&(heap->arr[elem]),&(heap->arr[parent(elem)]));
		elem = parent(elem);
	}

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

		// Poner el último elemento al principio
		heap->arr[0] = heap->arr[last];
		elem=0;
		while(left(elem)<heap->size)
		{
			min = left(elem);

			// Tiene hijo derecho y ademas el hijo derecho
			// es más pequeño que el izquierdo
			if(right(elem) < heap->size && heap->arr[right(elem)] < heap->arr[left(elem)])
				min = right(elem);

			if(heap->arr[elem] > heap->arr[min])
				swap(&heap->arr[elem], &heap->arr[min]);

			elem = min;
		}

	}

	return retval;
}
