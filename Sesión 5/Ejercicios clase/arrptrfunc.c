/*
 * arrptrfunc.c
 *
 *  Created on: 1 feb 2023
 *      Author: jluis
 */
#include <stdio.h>

int sumar(int a,int b)
{
	return(a+b);
}

int restar(int a,int b)
{
	return(a-b);
}

int multiplicar(int a,int b)
{
	return(a*b);
}

int main()
{
	// Se define un arreglo de apuntadores a funciones
	// Inicializamos cada uno de los elementos del arreglo
	// con las funciones a las que apunta
	int (*funcarr[])(int,int) = {sumar,restar,multiplicar};
	int i;
	int res;

	// Recorriendo el arreglo de apuntadores a funciones como
	// arreglo
	for(i=0;i<3;i++)
	{
		res = funcarr[i](10,20);
		printf("El resultado es %d\n",res);
	}
}
