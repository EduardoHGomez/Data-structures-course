#include <stdio.h>

typedef struct
{
    float x, y;
} vector;

int main()
{
    vector v1 = {4,5};
    vector *vp;
    vp = &v1;

}