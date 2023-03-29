/*
 * promcalifs.c
 *
 *  Created on: 27 feb 2023
 *      Author: jluis
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	int calificacion,suma=0,contador=0;
	float promedio;

	fp = fopen("calificaciones.txt","r");
	if(fp==NULL)
	{
		fprintf(stderr,"No se puede abrir el archivo\n");
		exit(1);
	}

	while(!feof(fp)) // Mientras no sea el fin del archivo
	{
		fscanf(fp,"%d",&calificacion);
		contador++;
		suma = suma + calificacion;
	}
	fclose(fp);

	promedio = (float) suma / contador;

	printf("El promedio de %d calificaciones es %6.2f\n",contador,promedio);
}


