/*
 * verfloat.c
 *
 *  Created on: 25 ene 2023
 *      Author: jluis
 */
#include <stdio.h>

void printbin(int n)
{
	int i;
	unsigned int masc = 0x80000000; // en binario es 1000 0000 0000 0000 0000 0000 0000 0000

	for(i=0;i<32;i++)
	{
		if(n & masc)
			printf("1");
		else
			printf("0");
		masc = masc >> 1;
	}
}

int main()
{
	float n;
	void *p;
	int *ip;

	setbuf(stdout,NULL);

	printf("Dame un valor en punto flotante ");
	scanf("%f",&n);

	p = &n;
	ip = p;

	printf("%X\n",*ip);
	printbin(*ip);
}

