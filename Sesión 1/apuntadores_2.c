#include <stdio.h>

int main (void)
{
    char c1 = 'A';
    char c2 = '6';

    char *pc = &c1;
    *pc = 'B';
    
    pc = &c2;
    *pc = '7';
}