#include <stdio.h>

int main()
{
    char ac[] = {0,1,2,3};
    int *ip;
    void *vp;

    vp = ac;
    ip = vp;
    printf("%08X", *ip); //Imprime 03020100
    /*
    Se imprime de acuerdo con el orden Little Endian dado que el arreglo
    comienza con el LSB mientras el último byte es el MSB
    */

    ip = (int *) ac;
    /*
    Es el equivalente a 
    vp = ac;
    ip = pv
    */
}