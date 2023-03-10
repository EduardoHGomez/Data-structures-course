/*
 * Paso de parámetros 
 *
 *  Created on: 23 ene 2023
 *      Author: jluis
 */
#include <stdio.h>

void suma(int *px,int y)
{
	*px = *px + y;
}

int main()
{
	int x=4,y=5;

	suma(&x,y);

	printf("x = %d\n",x);
}

