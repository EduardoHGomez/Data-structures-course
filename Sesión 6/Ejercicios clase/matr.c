/*
 * matr.c
 *
 *  Created on: 8 feb 2023
 *      Author: jluis
 */

#include <stdio.h>

int mayor(void *p,int r,int c)
{
	int *ip = p;
	int i;
	int max = 0;

	for(i=0;i<r*c;i++)
	{
		if(*ip > max)
			max = *ip;
		ip++;
	}

	return(max);
}

int main()
{
	int mat[3][3] = {
			{7,9,2},
			{10,8,0},
			{6,5,4}
	};

	printf("El número mayor es %d\n",mayor(mat,3,3));
}

