/*
 * ejemplolista.c
 *
 *  Created on: 24 mar. 2023
 *      Author: jluis
 */
#include <stdio.h>
#include "list.h"

int main()
{
	LIST l1=list_create();
	int *n;
	int i;

	for(i=0;i<10;i++)
		list_add(l1,int_create(i));

	for(i=0;i<list_size(l1);i++)
	{
		n=list_get(l1,i);
		printf("%d\n",*n);
	}

	list_destroy(l1);
}

