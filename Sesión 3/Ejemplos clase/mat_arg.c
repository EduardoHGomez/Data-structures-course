/*
 * mat_arg.c
 *
 *  Created on: 25 ene 2023
 *      Author: jluis
 */
#include <stdio.h>

void printmat1(int mat[4][4])
{
	int i,j;

	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			printf("%2d\t",mat[i][j]);
		printf("\n");
	}
	printf("\n");
}

void printmat2(int mat[][4],int rows)
{
	int i,j;

	for(i=0;i<rows;i++)
	{
		for(j=0;j<4;j++)
			printf("%2d\t",mat[i][j]);
		printf("\n");
	}
	printf("\n");
}

void printmat3(void *mat,int rows,int cols)
{
	int i,j;
	int *arrnum;

	arrnum = mat;

	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
		{
			printf("%2d\t",*arrnum);
			arrnum++;
		}

		printf("\n");
	}
	printf("\n");
}

void printmat4(void *mat,int rows,int cols)
{
	int i,j;
	int *arrnum;

	arrnum = mat;

	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
			printf("%2d\t",*(arrnum+i*cols+j));

		printf("\n");
	}
	printf("\n");
}

void printmat5(int *arrnum,int rows,int cols)
{
	int i,j;

	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
			printf("%2d\t",*(arrnum+i*cols+j));

		printf("\n");
	}
	printf("\n");
}

int main()
{
	int mat_a[4][4] =  {{ 0, 1, 2, 3},
						{ 4, 5, 6, 7},
						{ 8, 9,10,11},
						{12,13,14,15}};

	printmat1(mat_a);
	printmat2(mat_a,4);
	printmat3(mat_a,4,4);
	printmat4(mat_a,4,4);

	/* Aquí si fue necesario hacer el cast por que la función
	 * recibe un apuntador a entero y no un apuntador void
	 * como los ejemplos anteriores */
	printmat5((int *) mat_a,4,4);


	return(0);
}

