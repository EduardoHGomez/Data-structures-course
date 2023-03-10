/*
 * Apuntadores a estructuras y cómo acceder a sus elementos de las dos formas distintas
 *
 *  Created on: 23 ene 2023
 *      Author: jluis
 */
#include <stdio.h>

typedef struct {
	double x,y;
} VEC2;

int main()
{
	VEC2 v = {1,2};
	VEC2 *pv;	// Definiendo un apuntador a una estructura VEC2

	printf("x=%5.2f, y=%5.2f\n",v.x,v.y);

	pv = &v; // pv contiene la dirección de la variable v

	//LAS DOS FORMASA DE ACCEDER
	printf("x=%5.2f, y=%5.2f\n",(*pv).x,(*pv).y);
	printf("x=%5.2f, y=%5.2f\n",pv->x,pv->y);
}

