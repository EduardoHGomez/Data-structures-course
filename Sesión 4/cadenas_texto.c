/*
Distinguir las partes de la memoria
donde se guardan las cadenas
*/


#include <stdio.h>
#include <string.h>

int main()
{
    char num1[] = "Uno";
    char *num2 = "Dos";

    printf("La direccion de num1 es %p\n", num1);
    printf("La direccion de que tiene num2 es %p\n", num2); //Pool de cadenas
    printf("La direccion de num2 es %p\n", &num2);

    strcpy(num1, "UNO");
    //num1 = "UNO"; No se puede
    //strcpy(num2, "UNO");
    num2 = "DOS";
    //Al crear "DOS" se crea un nuevo espacio
    printf("La direccion de que tiene num2 es %p\n", num2);

    printf("%s\n", num1);
    printf("%s\n", num2);
    printf("%p\n%p\n", num1, &num2);
}