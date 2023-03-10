/*
 * union.c
 *
 *  Created on: 22 feb 2023
 *      Author: jluis
 */
#include <stdio.h>

union U1 {
	unsigned int i;
	unsigned short s[2];
	unsigned char c[4];
};

int main()
{
	union U1 u;

	u.c[0] = 0x12;
	u.c[1] = 0x34;
	u.c[2] = 0x56;
	u.c[3] = 0x78;

	printf("s[0] = %X, s[1] = %X\n",u.s[0],u.s[1]);
	printf("u = %X\n",u.i);
}

