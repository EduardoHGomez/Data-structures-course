/*
 * sizedoc.c
 *
 *  Created on: 1 mar. 2023
 *      Author: eduar
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	int pos;

	fp = fopen("Maninfo.docx","rb");
	if(fp==NULL)
	{
		fprintf(stderr,"Error al abrir el archivo\n");
		exit(1);
	}

	fseek(fp,0,SEEK_END);
	pos = ftell(fp);

	fclose(fp);
	printf("El tamaño del archivo es %d\n",pos);

}


