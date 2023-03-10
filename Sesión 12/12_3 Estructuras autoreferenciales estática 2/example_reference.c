#include <stdio.h>

void add_by_value(int *n)
{   
    (*n)++;
}

void add_by_reference(int **ptr)
{    /***
     * AQUÍ SI MODIFICO EL CONTENIDO DE PTR, TANTO LA DIRECCION
     DONDE APUNTA PTR COMO EL CONTENIDO DE DONDE APUNTA PTR
     SÍ CAMBIA
    */
   printf("Pointer in function as reference: %p\n", ptr);

   /**
    * Si imprimera &ptr, entonces me manda a una copia de ptr
    * pero no es necesario analizarlo dado esto me da una ubicación
    * de la memoria local para procesar ptr
   */
   (**ptr)++;
}

void add_by_how_i_know(int*ptr)
{
    /***
     * AL USAR PTR SE ENVIA COMO UNA COPIA, NO COMO REFERENCIA
     * PERO LA DIRECCIÓN DONDE APUNTA ES LA MISMA
    */
    printf("Pointer in function as value (how i know): %p\n", &ptr);
    (*ptr)++;
}


int main()
{
    int n = 10;
    int *ptr = &n;
    printf("\nORIGINAL ADDRESS OF PTR %p\n", &ptr);

    add_by_value(&n);
    //printf("%d\n", n);
    
    add_by_reference(&ptr);
    //printf("%d\n", n);

    
    add_by_how_i_know(ptr);
    //printf("%d\n", n);
}