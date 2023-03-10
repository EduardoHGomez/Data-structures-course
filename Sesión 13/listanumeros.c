/*
 * listanumeros.c
 *
 *  Created on: 8 mar 2023
 *      Author: jluis
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct STRNUM {
	int num;
	struct STRNUM *next;
};

/* Hacer una estructura con los dos apuntadores de la lista
 * "first" y "last", para poder manejar ambos apuntadores
 * de la mista lista con una sola variable
 */
typedef struct {
	struct STRNUM *first,*last;
} LIST;

void insert(LIST *l,int n);

int main()
{
	LIST lista = {NULL,NULL};
	struct STRNUM *ptr = NULL,*todestroy = NULL;
	clock_t inicio,fin;

	int num;

	// Para la consola de eclipse, y asegurar que los
	// printf se muestran antes de cada scanf
	setbuf(stdout,NULL);

	inicio =clock();
	do {
		printf("Dame un número (0 para terminar) :");
		scanf("%d",&num);
		if(num!=0)
		{
			// Buscar a ver si está en la lista
			ptr = lista.first; // Apunta al inicio

			// Mientras no llegue al final de la lista
			// y además no hemos encontrado el número
			while(ptr!=NULL && ptr->num!=num)
				ptr = ptr->next; // Hacemos que ptr
								 // apunte al siguiente

			// Si no se encontró
			if(ptr==NULL)
				insert(&lista,num);
			else
				printf("El número %d ya está en la  lista\n",num);
		}

	} while(num!=0);


	// Recorrer la lista y mostrar los números
	ptr = lista.first;

	// Mientras no llegue al final de la lista
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->num);
		ptr = ptr->next;
	}
	fin =clock();

	// Destruir la lista para liberar la memoria
	ptr=lista.first;
	while(ptr!=NULL)
	{
		todestroy = ptr;
		ptr = ptr->next;
		free(todestroy);
	}

	printf("Tiempo = %5.2f segundos",(fin-inicio)/1000.0);
}

void insert(LIST *l,int n)
{
	// Crear el nodo
	struct STRNUM *new = malloc(sizeof(struct STRNUM));

	// Poner los valores en la estructura
	new->num = n;
	new->next = NULL;

	// Si first apunta a NULL es que la lista está vacía
	// y hay que poner el nodo como el primero de la lista
	if(l->first==NULL)
		l->first = new;
	else
		l->last->next = new; // Si no, hay que ponerlo después
							 // de last

	l->last = new;	// last debe apuntar al nodo que acabamos
					// de poner, que es el último
}
