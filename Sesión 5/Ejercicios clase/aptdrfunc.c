/*
 * aptdrfunc.c
 *
 *  Created on: 1 feb 2023
 *      Author: jluis
 */
#include <stdio.h>

struct OPERACION {
	int (*func)(int,int);
	int a;
	int b;
};

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
	//Declarar un arreglo de estructuras y establecer los valores

	struct OPERACION op[] = {{sumar,10,20},
							 {restar,32,10},
							 {multiplicar,6,2}
							};
	int i;
	int a,b,result;

	for(i=0;i<3;i++)
	{
		a = op[i].a;
		b = op[i].b;
		result = op[i].func(a,b);
		printf("El resultado de la operación %d es %d\n",i,result);
	};
}
