#include <stdio.h>
#include <string.h>
#include "set.h"
#include <time.h>
#include <stdlib.h>

int comparador_enteros(TYPE a,TYPE b);
int color_code(char *color_name);
int comparador_colores(TYPE color1,TYPE color2);
void print_entero(TYPE data);
void print_color(TYPE data);

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

int comparador_enteros(TYPE a,TYPE b)
{
	int ia = *((int *) a);
	int ib = *((int *) b);
	return ia - ib;
}

int color_code(char *color_name)
{
	int retval = 0;
	if(strcmp(color_name,"NEGRO")==0)
		retval = 10;
	if(strcmp(color_name,"ROJO")==0)
		retval = 20;
	if(strcmp(color_name,"VERDE")==0)
		retval = 30;
	if(strcmp(color_name,"AZUL")==0)
		retval = 40;

	return retval;
}

int comparador_colores(TYPE color1,TYPE color2)
{
	return(color_code(color1) - color_code(color2));
}

void print_entero(TYPE data)
{
	printf("%d\n", *((int *)data));
}

void print_color(TYPE data)
{
	printf("{");
	printf("\"color\":\"%s\"",(char *) data);
	printf("}\n");
}
