#include <stdio.h>
#include "stack.h"

int getCharIndex(char c)
{
    if (c == ')')
        return 0;
    else if (c == ']')
        return 1;
    else if (c == '}')
        return 2;
}

int main(void)
{
    FILE *f = fopen("fuente.c", "r");
    char c;

    STACK s1 = stack_create();
    char chars_to_check[3] = {'(','[','{'};
    int indice;
    char charToCompare;
    char *charGoal;
    while (!feof(f))
    {
        c = fgetc(f);
        if (c =='(' || c =='[' || c =='{')
        {
            stack_push(s1, char_create(c));
        }

        else if (c == ')' || c == ']' || c == '}')
        {
            indice = getCharIndex(c);
            charToCompare = chars_to_check[indice];
            charGoal = stack_pop(s1);

            if (charToCompare != *charGoal)
            {
                printf("INVALIDO\n");
                fclose(f);
                return 1;
            }
            
        }
        
    }
    fclose(f);
    printf("VALIDO\n");
    return 0;
}