#include <stdio.h>
#include "stack.h"
#include <string.h>

int main()
{
    char* name_test = calloc(30, sizeof(char));
    printf("Ingrese su nombre: ");
    scanf("%s", name_test);
    printf("%s\n", name_test);

    //Mudarlo a tipo STRING 
    STRING name = string_create(name_test);
    free(name_test);

    //----------Algoritmo----------

    STACK stack_name = stack_create();

    for (int i = 0; i < strlen(name); i++)
    {
        stack_push(stack_name,char_create(name[i]));
    }

    char *letra;
    while (!stack_empty(stack_name))
    {
        letra = stack_pop(stack_name);
        printf("%c", *letra);
    }

}