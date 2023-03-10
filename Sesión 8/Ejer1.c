#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimir_renglon(int *renglon, int columnas)
{
    printf("[");
    for (int i = 0; i < columnas; i++)
    {
        if ((i) == columnas - 1)
            printf("%d]\n", columnas);
        else
            printf("%d, ", columnas);

    }
    
}

int main()
{
    srand(time(NULL));
    int r = (rand() % (20 - 2 + 1)) + 2;
    printf("Numero aleatorio: %d\n", r);

    int **mat = malloc(r * sizeof(int*));

    for (int i = 1; i < r+1; i++)
    {
        mat[i] = malloc(i * sizeof(int));
        imprimir_renglon(mat[i], i);
    }
    
}