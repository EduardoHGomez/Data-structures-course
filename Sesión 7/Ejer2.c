#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Solicitar al usuario el tamaño del arreglo
    printf("Ingrese la cantidad de numeros: ");
    int n = 0;
    scanf("%d", &n);

    //Establecer el tamaño del arreglo = tamaño * memoria a almacenar por elemento
    int *numeros = malloc(n * sizeof(int)); // VER LO DEL CAST -- Apuntador a void y después int

    //Solicitar cada número
    float promedio;
    for (int i = 0; i < n; i++)
    {
        printf("Ingrese el valor del elemento %d: ", i);
        scanf("%d", numeros+i); 
        promedio += *(numeros+i);
    }
    
    promedio /= n;

    for (int i = 0; i < n; i++)
    {
        printf("%d ", numeros[i]); // *(numeros+i)
    }

    printf("\nPromedio es: %.2f\n", promedio);
    printf("Tamaño en bytes de memoria usada es de: %d\n", n * sizeof(numeros));
    /*Si no se multiplica por "n", entonces solo se mostrará 4
    dado que apunta al espacio de la primera dirección, siendo un int
    */

    free(numeros);
    
}
