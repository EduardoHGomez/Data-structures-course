#include <stdio.h>
#include <math.h>
#include <stack.h>

int main()
{
    STACK operandos = stack_create();
    STACK operadores = stack_create();
    char expresion[20];
    char *ptr = expresion;

    setbuf(stdout, NULL);

    printf("Escribe una expresión aritmética : ");
    scanf("%s", expresion);



}