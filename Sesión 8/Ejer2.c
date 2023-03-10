#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void imprimir_espacios(int dimension)
{
    for (int i = 0; i < dimension; i++)
        printf("  ");
}

void imprimir_matrices(int **matA, int **matB, int **matC, int dimension)
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
        //Matriz A
        for (int j = 0; j < dimension; j++)
            printf("%d " , matA[i][j]);
        printf("\t");

        //Matriz B
        for (int j = 0; j < dimension; j++)
            printf("%d " , matB[i][j]);
        printf("\t");

        //Matriz C
        for (int j = 0; j < dimension; j++)
            printf("%d " , matC[i][j]);
        printf("\t");

        printf("\n");
    }
    
}

int resultado_celda(int **matrizA, int** matrizB, int renglon, int columna, int dimension)
{   
    /**
     * NO LA USÉ
     * MODIFICAR PARA QUE QUEDÉ BIEN
    */
    int resultado = 0;
    for (int i = 0; i < dimension; i++)
    {
        resultado += (*(*matrizA+renglon)+i) * (*(*matrizB+renglon+i)+columna);
    }
    
    return resultado;
}

void multiplicar_matrices(int **matrizA, int **matrizB, int **matrizC, int dimension)
{
    //Aquí se guardarán los resultados de las dos matrices en la matriz C
    for (int renglon = 0; renglon < dimension; renglon++){
        for (int columna = 0; columna < dimension; columna++){
            for (int k = 0; k < dimension; k++)
                *(*(matrizC+renglon)+columna) += matrizA[renglon][k]*matrizB[k][columna];
                /**
                 * matrizA[renglon][k]*matrizB[k][columna] es equivalente a 
                 * *(*(matrizA + renglon) + k)
                */
        }
        
    }
}

void inicializar_valores(int **matriz, int dimension)
{
    for (int i = 0; i < dimension; i++)
        for (int j = 0; j < dimension; j++)
            *(*(matriz+i)+j) = rand() % 10;
}

int main()
{
    srand(time(NULL));
    //Solicitar el tamaño de la matriz nxn
    int dimension;
    printf("Ingrese la dimension de las matrices: ");
    scanf("%d", &dimension);

    int **matA = malloc(dimension * sizeof(int* ));
    for (int i = 0; i < dimension; i++)
    {
        matA[i] = malloc(dimension * sizeof(int));
    }

    int **matB = malloc(dimension * sizeof(int * ));
    for (int i = 0; i < dimension; i++)
    {
        matB[i] = malloc(dimension * sizeof(int));
    }
    
    inicializar_valores(matA, dimension);
    inicializar_valores(matB, dimension);
    

    int **matC = malloc(dimension * sizeof(int *));
    for (int i = 0; i < dimension; i++)
    {
        matC[i] = calloc(dimension, sizeof(int));
    }

    multiplicar_matrices(matA, matB, matC, dimension);
    
    imprimir_matrices(matA, matB, matC, dimension);
    //Liberar cada memoria tomada por mat
    for (int i = 0; i < dimension; i++)
    {
        free(matA[i]);
        free(matB[i]);
        free(matC[i]);
    }
    
    free(matA);
    free(matB);
    free(matC);


}