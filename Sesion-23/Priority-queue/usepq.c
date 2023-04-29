#include <stdio.h>
#include "priorityqueue.h"

#define FIN -1

int compints(TYPE n1,TYPE n2);
void printint(TYPE n);

int main()
{
	PRIORITYQUEUE pq1 = priorityqueue_create(100,compints,printint);
	int nums[] = {10,12,5,7,9,19,6,8,17,23,29,2,5,FIN};
	int i=0;
	int *n;

	while(nums[i]!=FIN)
	{
		priorityqueue_offer(pq1,int_create(nums[i]));
		i++;
	}

	printf("\nPeek: %d\n", int_val((priority_peek(pq1))));

	printf("Size: %d\n", priority_size(pq1));

	printf("Is empty: %d\n", priorityqueue_isempty(pq1));

	for(i=0;i<13;i++)
	{
		n = priorityqueue_poll(pq1);
		printf("%d\t",*n);
	}
	printf("\n");
	printf("Is empty: %d\n", priorityqueue_isempty(pq1));

}

int compints(TYPE n1,TYPE n2)
{
	int num1 = *((int *) n1);
	int num2 = *((int *) n2);

	return num1 - num2;
}

void printint(TYPE n)
{
	int num = *((int *) n);
	printf("%d ",num);
}
