/*
 * printbits.c
 *
 *  Created on: 8 feb 2023
 *      Author: jluis
 */
#include <stdio.h>

void printbits(void *p)
{
	int i;
	unsigned int mask = 0x80000000;
						// 1000 0000 0000 0000 0000 0000 0000 0000
	unsigned int n = *((unsigned int *) p);

	for(i=0;i<32;i++)
	{
		if(n & mask)	// Si es diferente de 0
			printf("1");
		else
			printf("0");
		mask = mask >> 1;
		if(i%4==3)
			printf(" ");
	}
	printf("\n");
}

int main()
{
	int x1 = 1234;
	int x2 = 0x1234;
	int x3 = 0755;
	char *s = "HOLA";
	float f1 = 1.5;
	float f2 = 3.5;

	printbits(&x1);
	printbits(&x2);
	printbits(&x3);
	printbits(s);
	printbits(&f1);
	printbits(&f2);
}


