#include <stdio.h>

int main()
{
    int n, size = 10;
    printf("Ingrese un numero limite: ");
    scanf("%d", &n);

    int lista[10] = {0,0,0,0,0,0,0,0,0,0};

    for (int i = 2; i < n; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (j % lista[i] == 0)
            {
                lista[size] = i;
                size++;
            }
        }
        
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", lista[i]);
    }
    

}