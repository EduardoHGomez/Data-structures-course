#include <stdio.h>

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


int main(void)
{
    char cad[] = "Hey que onda";
    printf("La longitud de cad es %d\n", lenght(cad));
}