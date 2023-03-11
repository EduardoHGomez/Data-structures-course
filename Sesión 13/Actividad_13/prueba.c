#include <stdio.h>
#include <stdlib.h>


int main()
{
    int limite;
    printf("Ingrese un numero: ");
    scanf("%d", &limite);

    int SIZE = 1;
    int *lista_primos = malloc(SIZE * sizeof(int));
    *(lista_primos) = 2; 
    //*(lista_primos + 1) = 3; *(lista_primos + 2) = 5; *(lista_primos + 3) = 7;

    int resultado, is_prime = 0;
    
    for (int i = 2; i <= limite; i++)
    {   is_prime = 1;
        for (int j = 0; j < SIZE; j++)
        {   
            if ((i != *(lista_primos+j)) && (i%*(lista_primos+j) == 0))  
            {
                is_prime = 0;
                break;
            } 
        }
        if (is_prime && i > 2)
        {
            printf("%d es primo\n", i);
            SIZE++;
            lista_primos = realloc(lista_primos, SIZE * sizeof(int));
            if (lista_primos == NULL) 
            {
                printf("Error: no se pudo asignar memoria\n");
                exit(1);
            }
            *(lista_primos + SIZE - 1) = i;
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", lista_primos[i]);
    }
    
    free(lista_primos);
}
