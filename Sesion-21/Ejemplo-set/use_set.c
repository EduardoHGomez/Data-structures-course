/*
 * use_set.c
 *
 *  Created on: 19 abr 2023
 *      Author: jluis
 */
#include <stdio.h>
#include <string.h>
#include "set.h"

int comparador_enteros(TYPE a,TYPE b);
int color_code(char *color_name);
int comparador_colores(TYPE color1,TYPE color2);
void print_entero(TYPE data);
void print_color(TYPE data);

int main()
{
	SET s1 = set_create(comparador_enteros, print_entero);

	set_add(s1,int_create(5));
	set_add(s1,int_create(4));
	set_add(s1,int_create(7));
	set_add(s1,int_create(9));

	printf("Tamano del conjunto %d\n",set_size(s1));

	set_print(s1);

}

/*
 * Esta función regresa
 * 	Un valor positivo si a es mayor que b
 * 	Un valor negativo si a es menor que b
 * 	0 si a y b son iguales
 */
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


/*
 * La comparación de a con b se hace mediante la resta de a - b
 * Si la resta te da como resultado un valor positivo, entonces a > b
 * Si la resta te da como resultado un valor negativo, entonces a < b
 * Si la resta te da como resultado 0, entonces son iguales
 */
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


// ----------------PROGRAMA ANTERIOR------------------
/**
 * int main()
{
	SET s1 = set_create(comparador_colores,
			print_color);


	set_add(s1,string_create("ROJO"));
	set_add(s1,string_create("NEGRO"));
	set_add(s1,string_create("VERDE"));
	set_add(s1,string_create("ROJO"));
	set_add(s1,string_create("NEGRO"));
	set_add(s1,string_create("VERDE"));
	set_add(s1,string_create("AZUL"));


	printf("Tamano del conjunto %d\n",set_size(s1));

	set_print(s1);

}
*/