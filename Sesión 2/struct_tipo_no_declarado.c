#include <stdio.h>

struct vector
{
    float x, y;
};

int main()
{
    struct vector v1 = {4,5};
    printf("%f %f", v1.x, v1.y);
}