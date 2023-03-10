/*
 * Arreglos como argumentos
 *
 *  Created on: 23 ene 2023
 *      Author: jluis
 */
#include <stdio.h>

#define FIN 0

int numscount(int *inicio)
{
	int *p = inicio;
	while (*p != FIN)
		p++;
	return (p - inicio);
}

int sumarr(int *arr)
{
	int tot = 0;

	while(*arr!=FIN)
	{
		tot = tot + *arr;
		arr++;
	}
	return(tot);
}

void printarr(int *arr,int inicio,int cuantos)
{
	int *p = arr + inicio;
	int i;

	for(i=0;i<cuantos;i++)
	{
		if(*p==FIN)
			break;
		printf("[%d]",*p);
		p++;
	}
	printf("\n");
}

int main()
{
	int nums[] = {1,2,3,4,5,6,7,8,FIN};

	printf("Números en el arreglo = %d\n",numscount(nums));
	printf("La suma es %d\n",sumarr(nums));

	printarr(nums,3,10);
}

