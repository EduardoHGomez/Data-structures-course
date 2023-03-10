#include <stdio.h>

int main(void)
{
    char c1 = 'A';
    char* pc1 = &c1;

    printf("%p\n", &c1); // Dirección de c1 = almacenada en el puntero
    printf("%p\n", pc1); // Dirección almacenada en el puntero 
    printf("%p\n", &pc1); // Dirección del puntero

    *pc1 = 'b';

    printf("%c\n", c1);
}