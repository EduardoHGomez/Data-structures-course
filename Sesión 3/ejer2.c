#include <stdio.h>

void printptrarr(char *a[],int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", *(a+i));
    }
    

}

int main()
{

    char arr[][10]={"Uno","Dos","Tres","Cuatro","Cinco","Seis",
                    "Siete","Ocho","Nueve","Diez","Once","Doce"};

    char *arreglo_apuntadores[12];

    for (int i = 0; i < 12; i++)
    {
        arreglo_apuntadores[i] = arr[i];
    }

    printptrarr(arreglo_apuntadores, 12);
    
}