/*
 * Solución a la tarea de la actividad 1
 *
 *  Created on: 23 ene 2023
 *      Author: jluis
 */
#include <stdio.h>

int lenght(char *s)
{
	int cont = 0;

	while(*s)
	{
		cont++;
		s++;
	}

	return(cont);
}

int main()
{
	char saludo[] = "Hola mundo";

	printf("La longitud de la cadena es %d\n",lenght(saludo));
	printf("La longitud de la cadena es %d\n",lenght(&saludo[0]));

	printf("La longitud de la cadena es %d\n",lenght(&saludo[4]));

	char *pointer = saludo;
	printf("%c\n", *pointer);



}
