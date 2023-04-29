#include <stdio.h>

#define MAX_HEAP 100

#define parent(n) ((n-1)/2)
#define left(n) (n*2+1)
#define right(n) (n*2+2)
#define EMPTY -1

int heap[MAX_HEAP];
int size = 0; // Global

void swap(int *a,int *b);
void heap_offer(int num);
int heap_poll();

int main()
{
	int arr[] = {22,13,15,17,8,26,29,5,14,19,2,7,20,13,29};

	int i,n;

    printf("Introduciendo elemento del monticulo");

	for(i=0;i<15;i++)
		heap_offer(arr[i]);

	printf("\nRetirando elementos del monticulo\n");
	i=0;
	while((n=heap_poll())!=EMPTY)
		printf("%d\t",n);
}

void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heap_offer(int num)
{
	int elem = size; // Toma index del size

	heap[elem] = num; // Se inserta al último
	size++;

	while(elem > 0 && heap[elem] < heap[parent(elem)]) // Bubble up y obtener valor del parent
	{
		swap(&heap[elem], &heap[parent(elem)]);
		elem = parent(elem);
	}
}

int heap_poll()
{
	int retval;
	int last,elem,min;
	if(size==0)
		retval = EMPTY;
	else
	{
		retval = heap[0];
		size--;
		last = size;

		// Poner el último elemento al principio
		heap[0] = heap[last];
		elem=0;
		while(left(elem)<size)
		{
			min = left(elem);

			// Tiene hijo derecho y ademas el hijo derecho
			// es más pequeño que el izquierdo
			if(right(elem)<size && heap[right(elem)]<heap[left(elem)])
				min = right(elem);

			if(heap[elem]>heap[min])
				swap(&heap[elem],&heap[min]);

			elem = min;
		}

	}

	return retval;
}
