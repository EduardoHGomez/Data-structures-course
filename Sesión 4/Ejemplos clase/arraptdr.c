/*
 * arraptdr.c
 *
 *  Created on: 30 ene 2023
 *      Author: jluis
 */
#include <stdio.h>

void printmat1(int **mat,int rows,int cols)
{
	int i,j;

	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
			printf("%d\t",mat[i][j]);
		printf("\n");
	}
	printf("\n");
}

void printmat2(int **mat,int rows,int cols)
{
	int i,j;

	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
			printf("%d\t",*(*(mat+i)+j));
		printf("\n");
	}
	printf("\n");
}


void printmat3(int **mat,int rows,int cols)
{
	int i,j;
	int **pren = mat;
	int *pcol;

	for(i=0;i<rows;i++)
	{
		pcol = *pren;	// pcol apunta al elemento que está
						// en pren que es la dirección
						// de la primera columna del renglón

		for(j=0;j<cols;j++)
		{
			printf("%d\t",*pcol);
			pcol++;	// Recorriendo la dirección de cada columna
		}
		printf("\n");
		pren++;	// Paso al siguiente apuntador del arreglo de
				// apuntadores, que es donde está la dirección
				// donde inicia el siguiente reglón
	}
	printf("\n");
}


int main()
{
	int nums[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

	int *parr[] = {nums,nums+4,nums+8,nums+12};

	int r,c;

	setbuf(stdout,NULL);

	printf("Dame posición del renglón");
	scanf("%d",&r);

	printf("Dame posición de la colunna");
	scanf("%d",&c);

	/*
	 * En el primer caso estoy accediendo el dato como lo haría
	 * en cualquier matriz
	 */
	printf("El dato es %d\n",parr[r][c]);

	/*
	 * En el segundo caso, primero me voy a la posición del arreglo
	 * parr donde está el apuntador al renglón. Esto es parr[r].
	 * Después extraigo el contenido que es la dirección donde
	 * inician los datos del renglón r *parr[r]
	 * Después a esa dirección le sumo c para llegar a la
	 * dirección correspondiente a la colummna. *parr[r] + c
	 * Finalmente extraigo el contenido de esa dirección.
	 * *(parr[r] + c)
	 */
	printf("El dato es %d\n",*(parr[r] + c));

	/* En el tercer caso, uso parr que es la dirección al arreglo
	 * de apuntadores, le sumo r para irme a la posición del arreglo
	 * donde está el apuntador a la columa parr + r
	 * De ahí extraigo el contenido que es la dirección donde
	 * inicia el renglón y le sumo c que es la dirección de la columna
	 * *(parr+r) + c
	 * Finalemnte extraigo el contenido de esa dirección
	 * *(*(parr+r) + c)
	 */
	printf("El dato es %d\n",*(*(parr+r)+c));

	printmat1(parr,4,4);
	printmat2(parr,4,4);
	printmat3(parr,4,4);

}
