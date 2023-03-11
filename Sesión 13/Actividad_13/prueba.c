#include <stdio.h>
#include <stdlib.h>

int main()
{
    int limite;
    printf("Ingrese un numero: ");
    scanf("%d", &limite);

    int SIZE = 4;
    int *lista_primos = malloc(SIZE * sizeof(int));
    *(lista_primos) = 2; *(lista_primos + 1) = 3; *(lista_primos + 2) = 5; *(lista_primos + 3) = 7;

    int resultado, is_prime = 0;
    
    for (int i = 2; i <= limite; i++)
    {   is_prime = 1;
        for (int j = 0; j < SIZE; j++)
        {   
            if (i != *(lista_primos+j))
            {
                printf("i = %d j = %d resultado = %d\n", i, *(lista_primos+j), i%*(lista_primos+j));
                if (i%*(lista_primos+j) == 0)
                {
                    printf("no es primo\n");
                    break;
                }
            }
            
        }
        printf("\n");
        
    }

/**
 *     printf("--\nSIZE: %d\n", SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", *(lista_primos+i));
    }
*/
    
    
    free(lista_primos);
}

