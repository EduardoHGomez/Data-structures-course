#include <stdio.h>

void size (char *string)
{
    printf("\n");
    char *temp = string;
    printf("Temporal address: %p\n", temp);
    printf("Temporal address + 1: %p\n\n", temp + 1);

    temp = temp + 1;
    printf("Temporal address SHOULD PRINT + 1 != S + 1: %p\n", temp);
    printf("\n");
    return;
}

int main()
{
    char *s = "Hola 123";
    printf("Original address: %p\n", s);
    printf("Original address + 1: %p\n", s+1);
    size(s);

    s = s+1;
    printf("Original address + 1 [edited]: %p\n", s+1);
    
}