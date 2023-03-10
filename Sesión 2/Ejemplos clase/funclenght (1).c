/*
 * funclenght.c
 *
 *  Created on: 23 ene 2023
 *      Author: jluis
 */
#include <stdio.h>

int lenght(char *s)
{
	char *p = s;	// p apunte también al inicio de la cadena
	while(*p)
		p++;

	return(p - s);
}

int main()
{
	char saludo[] = "Hola mundo";

	printf("La longitud de la cadena es %d\n",lenght(saludo));
	printf("La longitud de la cadena es %d\n",lenght(&saludo[0]));

	printf("La longitud de la cadena es %d\n",lenght(&saludo[4]));
}
