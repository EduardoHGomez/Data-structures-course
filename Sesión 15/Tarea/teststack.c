/*
 * teststack.c
 *
 *  Created on: 15 mar 2023
 *      Author: jluis
 */
#include <stdio.h>
#include "stack.h"

int main()
{
	STACK s1 = stack_create();	// Crear un stack
	// int arr[] = {1,2,3,4,5,6,7};
	int i;
	float *num;

	for(i=0;i<7;i++)
		stack_push(s1,float_create(i*1.5));

	while(!stack_empty(s1))
	{
		num = stack_pop(s1);
		printf("%5.2f\n",*num);
	}

	stack_destroy(s1);
}

