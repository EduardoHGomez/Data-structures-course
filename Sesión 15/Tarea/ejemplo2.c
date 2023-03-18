#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    setbuf(stdout, NULL);
    int numero = 1;
    STACK stack1 = stack_create();

    do
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numero);
        if (numero != 0)
        {
            stack_push(stack1, int_create(numero));
        }
        
        
    } while(numero!=0);

    //---------PRUEBAS----------
    int *numero_imprimir;

    numero_imprimir = stack_peek(stack1);
    printf("TOP %d\n", *numero_imprimir);

    //---------FUNCION POP-------------
    while (!stack_empty(stack1))
    {
        numero_imprimir = stack_pop(stack1);
        printf("%d ", *numero_imprimir);
    }
    printf("\n");

    numero_imprimir = stack_peek(stack1);
    printf("TOP %d\n", *numero_imprimir);

}