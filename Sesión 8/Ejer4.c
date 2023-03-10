#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimir_matriz(int *mat, int filas, int columnas)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
            printf("%d ",  mat[columnas * i + j]);
        printf("\n");
    }
    printf("\n");
}

void matrix_copy(int *matrizIngreso, int *matrizDestino, int filas, int columnas)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matrizDestino[i*columnas + j] = matrizIngreso[i*columnas + j];
        }
        
    }
    
}

void inicializar_valores(int *matriz, int filas, int columnas)
{   //Valores aleatorios
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            *((matriz + columnas * i) + j) = rand() % 10;
        }
    }
}

int main()
{
    srand(time(NULL));
    int filas, columnas;
    printf("Ingrese las filas de la matriz: ");
    scanf("%d", &filas);

    printf("Ingrese las columnas de la matriz: ");
    scanf("%d", &columnas);

    int *matA = malloc(filas * columnas * sizeof(int));
    int *matB = malloc(filas * columnas * sizeof(int));

    inicializar_valores(matA, filas, columnas);
    matrix_copy(matA, matB, filas, columnas);

    printf("Matriz A: \n");
    imprimir_matriz(matA, filas, columnas);
    printf("Matriz B: \n");
    imprimir_matriz(matB, filas, columnas);

    free(matA);
    free(matB);

}