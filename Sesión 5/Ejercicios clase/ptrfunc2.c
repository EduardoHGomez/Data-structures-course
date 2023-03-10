/*
 * ptrfunc2.c
 *
 *  Created on: 1 feb 2023
 *      Author: jluis
 */
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

int operacion(int (*func)(int,int),int x,int y)
{
	return(func(x,y));
}

int main()
{
	int a=10,b=20,c;

	c = operacion(sumar,a,b);
	printf("El valor de c es %d\n",c);

	c = operacion(restar,a,b);
	printf("El valor de c es %d\n",c);

	c = operacion(multiplicar,a,b);
	printf("El valor de c es %d\n",c);

}


