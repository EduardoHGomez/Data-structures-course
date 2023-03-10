/*
 * bigendian.c
 *
 *  Created on: 8 feb 2023
 *      Author: jluis
 */
#include <stdio.h>

int main()
{
	char arr[] = {0,1,2,3}; // 4 bytes

	void *vp;
	int *ip;

	vp = arr; // vp apunta a arr
	ip = vp; // copio la dirección apuntada por vp a ip

	printf("%08X\n",*ip);


	char *saludo = "ADIOS";
	vp = saludo;
	ip = vp;
	printf("%08X\n",*ip);
}

