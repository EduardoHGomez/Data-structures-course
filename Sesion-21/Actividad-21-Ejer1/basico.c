#include <stdio.h>
#include <string.h>
#include "set.h"
#include <time.h>
#include <stdlib.h>

int comparador_enteros(TYPE a,TYPE b);
void print_entero(TYPE data);

/*EJERCICIO 1: Desarrollar las funciones para imprimir, destruir, y comparar */

int main()
{
	srand(time(NULL));
	SET s1 = set_create(comparador_enteros, print_entero);

	// Para el ejercicio básico se añadirán 20 números aleatorios
	int random;
	for (int i = 0; i < 20; i++)
	{
		random = rand() % 10;
		set_add(s1, int_create(random));
	}
	
	// Función para imprimir set
	set_print(s1);

	// Función para destruir
	printf("Size: %d", s1->size);
	set_delete(s1);
	

}

// Función para comparar
int comparador_enteros(TYPE a,TYPE b)
{
	int ia = *((int *) a);
	int ib = *((int *) b);
	return ia - ib;
}


void print_entero(TYPE data)
{
	printf("%d\n", *((int *)data));
}
