/*
 * listaprimos.c
 *
 *  Created on: 13 mar 2023
 *      Author: jluis
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX 1000

typedef struct STRNUM {
	int num;
	struct STRNUM *next;
} STRNUM;

int main()
{
	STRNUM *first=NULL,*last=NULL,*ptr=NULL, *destr=NULL;
	int i;
	int limite;
	int cont = 0;
	clock_t inicio,fin;
	float tiempo;

	inicio = clock();

	for(i=2;i<=MAX;i++)
	{
		if(first==NULL)
		{
			first = malloc(sizeof(struct STRNUM));
			first->num = i;
			first->next = NULL;
			last = first;
			cont++;
		}
		else
		{
			limite = sqrt(i);
			ptr = first;
			while(ptr!=NULL && ptr->num<=limite && i % ptr->num != 0)
				ptr = ptr->next;

			if(ptr==NULL || ptr->num>limite)	// No hay un divisor en la lista
			{
				ptr = malloc(sizeof(struct STRNUM));
				ptr->num = i;
				ptr->next = NULL;

				last->next = ptr;
				last = ptr;
				cont++;
			}
		}
	}

	fin = clock();
	tiempo = (fin-inicio) / 1000.0;

	ptr = first;
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->num);
		ptr = ptr->next;
	}

	printf("\nPrimos encontrados = %d\n",cont);
	printf("\nTiempo = %5.2f\n",tiempo);
	// Destruir la lista
	ptr = first;
	while(ptr!=NULL)
	{
		destr = ptr;
		ptr = ptr->next;
		free(destr);
	}
}
