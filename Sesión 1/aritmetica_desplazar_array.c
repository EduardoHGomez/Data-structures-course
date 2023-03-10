#include <stdio.h>

int main()
{
    int array[5] = {};
    *array = 4;

    printf("%p\n", array);
    printf("%d\n", array[0]);
}