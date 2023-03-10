#include <stdio.h>

int main(void)
{
    int array[5] = {0,0,0,0,0};

    *array = 5;

    printf("%d\n", *array);
    
    //Apuntador para navegar entre la dirección de cada elemento del arreglo

    int *parray = array;
    printf("%d\n",parray[0]);
    parray ++;

    *parray = 6;    
    printf("%d\n", parray[0]);
}