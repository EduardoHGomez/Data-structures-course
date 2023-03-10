#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    int arr[10] = {1234,34234,54234,1212,234234,12321,43433,5222,444,3333};

    fp = fopen("salida.txt", "w");

    if (fp == NULL)
    {
        printf("No fue posible abrir el archivo\n");
        exit(1);
    }

    for (int i = 0; i < 10; i++)
    {
        fprintf(fp, "%d\n", arr[i]);
    }
    fclose(fp);

    //Leer el archivo y desplegarlo
    fp = fopen("salida.txt", "r");
    if(fp == NULL)
    {
        printf("No se pudo abrir el archivo\n");
    }

    int numero;
    while(!feof(fp))
    {
        fscanf("%d", &numero);
        printf("%d\n", numero);
    }

    fclose(fp);
    
}