#include <stdio.h>
#include "stack.h"

int main()
{
    FILE *f = fopen("test.txt", "r");
    char c;

    STACK s1 = stack_create();

    while (!feof(f))
    {
        c = fgetc(f);
        if (c =='(' || c =='[' || c =='{') 
            stack_push(s1, char_create(c));

        if (c == ')' || c == ']' || c == '}')
        {
            char *char_to_check;
            char_to_check = stack_pop(s1);
            if (*char_to_check != c)
            {
                printf("Error\n");
                break;
            }
            
        }

        
    }
    
}