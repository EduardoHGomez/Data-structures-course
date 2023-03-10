/*
 * ejemplo1.c
 *
 *  Created on: 18 ene 2023
 *      Author: jluis
 */
#include <stdio.h>

int main()
{
	int i,j,k;
	int *pi;

	pi = &i;
	*pi = 1;

	pi = &j;
	*pi = 2;

	pi = &k;
	*pi = 3;

	printf("i=%d, j=%d, k=%d\n",i,j,k);
}


