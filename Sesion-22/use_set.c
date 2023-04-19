#include <stdio.h>
#include <string.h>
#include "set.h"

int comparador_enteros(TYPE a, TYPE b)
{
    int ia = *((int *) a);
    int ib = *((int *) b);
    /**
     * Esta función regresa un valor positivo si a es mayour que b
     * Un valor negativo si a es menor que b
     * 0 si son iguales
    */

   return ia-ib;
}

int color_code(char *color_name)
{
	int retval = 0;
	if(strcmp(color_name,"NEGRO"))
		retval = 0;
	if(strcmp(color_name,"ROJO"))
		retval = 1;
	if(strcmp(color_name,"VERDE"))
		retval = 2;
	if(strcmp(color_name,"AZUL"))
		retval = 3;

	return retval;
}

int comparador_colores(TYPE color1,TYPE color2)
{
	return(color_code(color1) - color_code(color1));
}

void print_entero(TYPE data)
{
	printf("%d\n", *((int *)data));
}

void print_color(TYPE data)
{
	printf("\n{\n");
	printf("\t\"color\":\"%s\"\n",(char *) data);
	printf("}\n");
}

int main()
{
    SET s1 = set_create(comparador_enteros, print_entero);
	set_add(s1, "ROJO");
}