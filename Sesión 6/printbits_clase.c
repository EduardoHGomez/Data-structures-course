#include <stdio.h>

void printbits(void *p, int bits)
{
    unsigned int mask = 0x80000000;
    unsigned int n = *((unsigned int *) p);

    for (int i = 0; i < bits; i++)
    {
        if (n & mask)
            printf("1");
        else
            printf("0");
        mask = mask >> 1;

        if (i%4 == 3)
            printf(" ");
    }
    printf("\n");
}

int main()
{
    int x1 = 1234;
    int x2 = 0x1234;
    int x3 = 0755; // Se imprime como 0001 1110 1101 siendo 111 = 7 101 = 5 101 = 5

    char *s = "Hola";
    float f1 = 1.5;
    float f2 = 3.5;

    printbits(&x1, 32);
    printbits(&x2, 32);
    printbits(&x3, 32);
    printbits(s, 32);
    printbits(&f1, 32);
    printbits(&f2, 32);
    
}