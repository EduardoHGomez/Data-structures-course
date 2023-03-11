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

    int resultado;
    
    for (int i = 2; i <= limite; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {   
            
            if (i % *(lista_primos + j) != 0 && i > 2)
            {
                
                SIZE++;
                realloc(lista_primos, SIZE*sizeof(int));
                *(lista_primos + SIZE - 1) = i;
                
            }
        }
        
    }

    printf("--\nSIZE: %d\n", SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", *(lista_primos+i));
    }
    
    
    free(lista_primos);
}

