#include <stdio.h>

struct Vec2
{
    float x, y;
} *pv;

int main()
{
    struct Vec2 vector1 = {4,5};
    pv = &vector1;

}