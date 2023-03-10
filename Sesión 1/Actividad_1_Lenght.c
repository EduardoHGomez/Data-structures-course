/*
  Actividad 1 - Longitud de cadena
  Jesús Octavio Huerta Santana
  José Eduardo Hurtado Gómez
*/

#include <stdio.h>

int lenght(char *string);

int main(void)
{
    char cad[] = "Hola mundo abc 123";
    printf("La longitud de cad es %d\n", lenght(cad));
}

int lenght(char *string)
{
    int i = 0;
    char *parray = string;
    while(1)
    {
        if (*parray == '\0')
        {
            return i;
        }
        parray++;
        i++;
    }
}
