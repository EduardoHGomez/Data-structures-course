#include <stdio.h>

#define MAX_HEAP 100
#define EMPTY -1
#define parent(n) ((n-1)/2)

int heap[MAX_HEAP];
int size = 0;

void heap_offer(int num);
void heap_poll();

int main()
{
    int arr[] = {22, 13, 15, 17, 8, 26, 29, 5, 14, 19, 2, 7, 20, 13, 29};
    int i;
    for (int i = 0; i < 15; i++)
    {
        heap_offer(arr[i]);
    }

    for (int i = 0; i < 15; i++)
    {
        printf("%d ", heap[i]);
    }
    
}

void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heap_offer(int num)
{
	int elem = size;

	heap[elem] = num;
	size++;

	while(elem>0 && heap[elem]<heap[parent(elem)])
	{
		swap(&heap[elem],&heap[parent(elem)]);
		elem = parent(elem);
	}

    while((n=heap_poll()) != EMPTY);
        printf("%d\n", n);

}

int heap_poll()
{
    int retval = heap[0];
    if (size == 0)
        retval = EMPTY;
    else
    {
        retval = heap[size];
        size--;
        last = size-1;

        heap[0] = heap[size-1]; // Poner elemento al principio
        elem = 0;
        while(left(elem) < size && heap[elem] > heap[left(elem)])
        {
            if(heap[elem] > heap[left(elem)])
                min = left(elem);

            if (right(elem) < size && heap[right(elem)] < heap[left(elem)])
                min = right(elem);

            if (heap[elem] > heap[min])
                swap(&heap[elem], &heap)
        }

    }
}