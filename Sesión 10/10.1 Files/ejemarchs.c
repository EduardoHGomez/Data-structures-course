/*
 * ejemarchs.c
 *
 *  Created on: 27 feb 2023
 *      Author: jluis
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp1,*fp2,*fp3;

	fp1 = fopen("hola1.txt","r+");
	if(fp1==NULL)
	{
		fprintf(stderr,"Error al abrir archivo\n");
		exit(1);
	}

	fp2 = fopen("hola2.txt","w+");
	if(fp2==NULL)
	{
		fprintf(stderr,"Error al abrir archivo\n");
		exit(1);
	}

	fp3 = fopen("hola3.txt","a+");
	if(fp3==NULL)
	{
		fprintf(stderr,"Error al abrir archivo\n");
		exit(1);
	}



	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
}


