#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMBLOQUE 10

int main()
{
    int *ptr, *ptr_new;

    //Memoria asignada
    int mem_asignada = TAMBLOQUE;

    //Espacio inicial para 10 ENTEROS
    ptr = malloc(mem_asignada * sizeof(int));
    if (ptr == NULL)
    {
        fprintf(stderr, "Error al asignar memoria \n");
        exit(1);
    }
    
    srand(time(NULL));
    int random = rand() % 100;
    printf("%d\n", random);

    for (int i = 0; i < random; i++)
    {
        /**
         * Hasta que i llega al límite de de un bloque
         * entonces a la memoria asignada se le suma el tamaño del bloque
         * (incrementa por múltiplos del tamaño del bloque)
        */
        if (i >= mem_asignada)
        {
            mem_asignada = TAMBLOQUE + mem_asignada;
            ptr_new = realloc(ptr, mem_asignada * sizeof(int));
            printf("ptr = %p, ptr_new = %p\n", ptr, ptr_new);

            if (ptr_new == NULL)
            {
                fprintf(stderr, "Error al asignar memoria\n");
                exit(1);
            }

            ptr = ptr_new;
            
        }
        ptr[i] = i;
    }

    for (int i = 0; i < mem_asignada; i++)
    {
        printf("%d ", ptr[i]);
    }
    
    /**
     * Al liberar la última dirección ptr, (investigar si con realloc se libera las
     * direcciones pasadas)
    */
    free(ptr);
}