#include <stdio.h>
#include "stack.h"

int getCharIndex(char c)
{
    printf("input: %c\n", c);
    if (c == ')')
        return 0;
    else if (c == ']')
        return 1;
    else if (c == '}')
        return 2;
}

int main(void)
{
    FILE *f = fopen("test.txt", "r");
    char c;

    STACK s1 = stack_create();
    char chars_to_check[3] = {'(','[','{'};

    while (!feof(f))
    {
        c = fgetc(f);
        if (c =='(' || c =='[' || c =='{')
        {
            stack_push(s1, char_create(c));
        }

    }

    for (int i = 0; i < s1->size; i++)
    {
        c = stack_pop(s1);
        printf("%c ", c);
    }
    
}