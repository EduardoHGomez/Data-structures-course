/*
 * realloc.c
 *
 *  Created on: 20 feb 2023
 *      Author: jluis
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMBLOQUE 10

int main()
{
	int *ptr,*ptr_new;
	int mem_asignada = TAMBLOQUE;
	int i;

	// Asignación inicial
	ptr = malloc(mem_asignada * sizeof(int));
	if(ptr==NULL)
	{
		fprintf(stderr,"Error al asignar memoria\n");
		exit(1);
	}

	srand(time(NULL));

	for(i=0;i<5+rand()%100;i++)
	{
		// Estoy tratando de escribir en memoria no asignada
		if(i>=mem_asignada)
		{
			mem_asignada = mem_asignada + TAMBLOQUE;
			ptr_new = realloc(ptr,mem_asignada * sizeof(int));
			printf("ptr=%p,ptr_new=%p\n",ptr,ptr_new);
			if(ptr_new==NULL)
			{
				fprintf(stderr,"Error al asignar memoria\n");
				exit(1);
			}
			ptr = ptr_new;
		}
		ptr[i] = i;
	}

	// Imprimir los datos que se guardaron en memoria dinámica
	for(i=0;i<mem_asignada;i++)
		printf("%d ",ptr[i]);

	free(ptr);
}

