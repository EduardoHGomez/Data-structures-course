#include <stdio.h>
#include <stdlib.h>



int main()
{
    int *ptr = NULL;
    printf("Direccion donde apunta p: %p\n", ptr);

    ptr = malloc(64 * sizeof(int));
    ptr[10] = 5000;
    printf("Direccion donde apunta p usando mmalloc %p\n\n", ptr);
    /*
     * Como se muestra después, esta dirección de memoria dinámica
     puede cambiar según si está disponible o se utiliza para
     otros procesos o variables
    */
    printf("Ciclo for asignando 5000 a la posicion 10:\n");
    for (int i = 0; i < 64; i++)
    {
        printf("%d: %p " , i, ptr+i);
    }
    
    
    free(ptr);
    /**
     * prt apunta a la misma dirección, sin embargo, acceder a su información
     * puede dar comportamiento no definido dado que ese espacio de memoria puede
     * ser utilizado por otras variables
    */
    printf("\nCiclo for despues de liberar ptr:");
    printf("\n\nDireccion de p despues de liberarla %p\n\n", ptr);

        for (int i = 0; i < 64; i++)
    {
        printf("%d: %p " , i, ptr+i);
    }

}