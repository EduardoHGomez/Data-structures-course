/*
 * Diferencias entre las localizaciones de los arreglos
 *
 *  Created on: 30 ene 2023
 *      Author: jluis
 */
#include <stdio.h>
#include <string.h>

int main()
{
	char num1[] = "Uno";
	char *num2 = "Dos";

	printf("la dirección de num1 es %p\n",num1);
	printf("la dirección de num2 es %p\n",num2);
	strcpy(num1,"UNO ");
	// num1 = "UNO";	NO SE PUEDE

	// strcpy(num2,"DOS");	NO SE PUEDE
	num2 = "DOS";
	printf("la dirección de num2 es %p\n",num2);

	printf("%s\n",num1);
	printf("%s\n",num2);
}
