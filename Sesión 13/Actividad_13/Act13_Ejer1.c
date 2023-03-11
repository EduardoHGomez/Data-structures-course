#include <stdio.h>
#include <stdlib.h>

struct STRNUM{
    int n;
    struct STRNUM *next;
};

typedef struct {
    struct STRNUM *first, *last;
} LIST;

int main()
{
    int n;
    printf("Ingrese un numero limite: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        /* code */
    }
    


}