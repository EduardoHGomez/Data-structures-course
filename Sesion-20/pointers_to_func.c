#include <stdio.h>

int fun(int a, int b)
{
    
    return a + b;
}

typedef int (*COMPAREFUNC)(int,int);
typedef void (*PRINTFUNC)(int);

int main()
{
    int resultado;
    COMPAREFUNC functions = &fun;
    resultado = functions(1,2);

    printf("Value of sum is %d\n", resultado);


}