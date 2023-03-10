/*
 * ptrfunc.c
 *
 *  Created on: 1 feb 2023
 *      Author: jluis
 */
#include <stdio.h>
#include <math.h>

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

int potencia(int a,int b)
{
	return((int)pow(a,b));
}

/*	Esta función no se puede apuntar con ptrfunc porque es
 * de diferente tipo en los valores que recibe y los valores
 * que devuelve
float sumarf(float a,float b)
{
	return(a+b);
}
*/

int main()
{
	int (*ptrfunc)(int,int);
	int a=10,b=20,c;

	ptrfunc = sumar;
	c = ptrfunc(a,b);
	printf("El valor de c es %d\n",c);

	ptrfunc = restar;
	c = ptrfunc(a,b);
	printf("El valor de c es %d\n",c);

	ptrfunc = multiplicar;
	c = ptrfunc(a,b);
	printf("El valor de c es %d\n",c);

}
