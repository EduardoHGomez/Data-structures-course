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
	ITERATOR ite;
	int *n;
	int i;

	for(i=0;i<10;i++)
		list_add(l1,int_create(i));

	printf("Recorriendo la lista hacia adelante\n");
	ite = list_begin(l1);
	while(list_has_next(ite))
	{
		ite = list_next(ite);
		n = ite->elem;
		printf("%d ",*n);
	}

	printf("\n\nRecorriendo la lista hacia atrás\n");
	ite = list_end(l1);
	while(list_has_prior(ite))
	{
		ite = list_prior(ite);
		n = ite->elem;
		printf("%d ",*n);
	}

	//----------Prueba eliminando el elemento 5-----------
	int position_to_remove = 10;
	printf("\n\nRemover elemento %d\n", position_to_remove);

	//Remover la posición
	ite = list_begin(l1);
	for (int i = 0; i < position_to_remove; i++)
	{
		ite = list_next(ite);
		list_remove(ite, l1);
	}
	
	
	//-------------Prueba volver a pasar la lista-----------
	printf("\nPrueba pasando todos los elementos despues de remover\n");
	ite = list_begin(l1);
	while(list_has_next(ite))
	{
		ite = list_next(ite);
		n = ite->elem;
		printf("%d ",*n);
	}



	list_destroy(l1);
}

