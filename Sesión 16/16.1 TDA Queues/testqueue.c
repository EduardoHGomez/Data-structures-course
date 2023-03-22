/*
 * testqueue.c
 *
 *  Created on: 17 mar 2023
 *      Author: jluis
 */
#include <stdio.h>

#include "queue.h"

int main()
{
	QUEUE q1 = queue_create();	// Crear una cola

	int i;
	int *num;

	for(i=0;i<7;i++)
		queue_offer(q1,int_create(i));

	while(!queue_empty(q1))
	{
		num = queue_poll(q1);
		printf("%d\n",*num);
	}

	queue_destroy(q1);
}

