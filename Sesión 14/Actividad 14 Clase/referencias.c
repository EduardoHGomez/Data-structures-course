#include <stdio.h>

void change(int **n)
{
    *n = NULL;
}

void change2(int **n)
{
    *n = NULL;
}


int main()
{
    int n = 5;
    int *ptr = &n;    

    printf("Direccion inicial: %p Direccion n: %p\n", ptr, &n);
    change(&ptr);

    printf("Direccion inicial: %p Direccion n: %p\n", ptr, &n);

        change(&ptr);

    printf("Direccion inicial: %p Direccion n: %p\n", ptr, &n);
    
}