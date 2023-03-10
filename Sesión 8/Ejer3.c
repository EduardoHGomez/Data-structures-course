#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimir_espacios(int dimension)
{
    for (int i = 0; i < dimension; i++)
        printf("  ");
}

void imprimir_matrices(int *matA, int *matB, int *matC, int dimension)
{
    printf("MatA=");
    imprimir_espacios(dimension);
    printf("MatbB=");
    imprimir_espacios(dimension);
    printf("MatC=");
    imprimir_espacios(dimension);
    
    printf("\n");
    for (int i = 0; i < dimension; i++)
    {
        //Matriz A *((matriz + dimension * i) + j) = matriz[dimension * i + j]
        for (int j = 0; j < dimension; j++) 
            printf("%d " , matA[dimension * i + j]);
        
        if ( i == dimension/2)
            printf(" * ");
        else
            printf("   ");

        //Matriz B
        for (int j = 0; j < dimension; j++)
            printf("%d " , matB[dimension * i + j]);
        printf("  ");

        if ( i == dimension/2)
            printf(" = ");
        else
            printf("   ");

        //Matriz C
        for (int j = 0; j < dimension; j++)
            printf("%03d " , matC[dimension * i + j]);
        printf("  ");

        printf("\n");
    }
}

void multiplicar_matrices(int *matrizA, int *matrizB, int *matrizC, int dimension)
{
    //Aquí se guardarán los resultados de las dos matrices en la matriz C
    for (int renglon = 0; renglon < dimension; renglon++)
    {
        for (int columna = 0; columna < dimension; columna++)
        {
            for (int k = 0; k < dimension; k++)
            {
                matrizC[renglon * dimension + columna] += 
                matrizA[dimension * renglon + k]* matrizB[dimension * k + columna];
            }
        }
    }
}

void inicializar_valores(int *matriz, int dimension)
{
    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            *((matriz + dimension * i) + j) = rand() % 10;
        }
    }
}

int main()
{
    srand(time(NULL));
    int dimension;
    printf("Ingrese el tamano de la matriz: ");
    scanf("%d", &dimension);

    int *matA = malloc(dimension * dimension * sizeof(int));
    int *matB = malloc(dimension * dimension * sizeof(int));
    int *matC = calloc(dimension * dimension, sizeof(int));

    inicializar_valores(matA, dimension);
    inicializar_valores(matB, dimension);

    multiplicar_matrices(matA, matB, matC, dimension);

    imprimir_matrices(matA, matB, matC, dimension);

    free(matA);
    free(matB);
    free(matC);

}