#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimir_matriz(int **matriz, int renglones, int columnas)
{
    for (int i = 0; i < renglones; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("%d ", *(*(matriz+i)+j));
        }
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));
    int renglones;
    int columnas;
    int r;

    printf("Ingrese los renglones: ");
    scanf("%d", &renglones);

    printf("Ingrese los columnas: ");
    scanf("%d", &columnas);

    int **matriz;
    matriz = malloc(renglones * sizeof(int *));

    for (int i = 0; i < renglones; i++)
    {
        matriz[i] = malloc(columnas * sizeof(int));
    }

    for (int i = 0; i < renglones; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            r = rand() % 10;
            *(*(matriz+i)+j) = r;
        }
        
    }
    imprimir_matriz(matriz,renglones,columnas);
    
    free(matriz);
}