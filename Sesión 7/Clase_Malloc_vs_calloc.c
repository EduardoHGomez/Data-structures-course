/*
 * mallocycalloc.c
 *
 *  Created on: 15 feb 2023
 *      Author: jluis
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int *p1, *p2;
	int i;

	p1 = malloc(100*sizeof(int));
	if(p1==NULL)
	{
		fprintf(stderr,"Falló asignación de memoria\n");
		exit(1);
	}

	p2 = calloc(100,sizeof(int));
	if(p2==NULL)
	{
		fprintf(stderr,"Falló asignación de memoria\n");
		exit(1);
	}

	printf("\nContenido de los datos apuntados por p1\n");
	for(i=0;i<100;i++)
		printf("%d ",p1[i]);

	printf("\nContenido de los datos apuntados por p2\n");
	for(i=0;i<100;i++)
		printf("%d ",p2[i]);

	memset(p1,0,100*sizeof(int));
	printf("\nDespués de inicializar, el contenido de los datos apuntados por p1\n");
	for(i=0;i<100;i++)
		printf("%d ",p1[i]);

	free(p1);
	free(p2);
}


