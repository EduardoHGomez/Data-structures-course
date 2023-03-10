/*
 * matrcar.c
 *
 *  Created on: 25 ene 2023
 *      Author: jluis
 */
#include <stdio.h>

void printcads(void *p,int cads,int len)
{
	int i;
	char *s = p;	// s apunta a la primera cadena

	// Recorrer cada una de las cadenas
	for(i=0;i<cads;i++)
	{
		printf("%s\n",s);
		s = s + len;	// Al terminar cada cadena, incremento
						// el apuntador en len que es la longitud
						// de cada una de las cadenas
	}
	printf("\n");
}

int main()
{
	char mat1[][6] = {"UNO","DOS","TRES"};
	char mat2[][6] = {  {'U','N','O',0,0,0},
						{'D','O','S',0,0,0},
						{'T','R','E','S',0,0}};

	char mat3[] = "UNO\0\0\0DOS\0\0\0TRES\0\0";
	char mat4[] = {'U','N','O',0,0,0,'D','O','S',0,0,0,'T','R','E','S',0,0};

	printcads(mat1,3,6);
	printcads(mat2,3,6);
	printcads(mat3,3,6);
	printcads(mat4,3,6);
}
