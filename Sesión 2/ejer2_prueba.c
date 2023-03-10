#include <stdio.h>
#include <math.h>

typedef struct {
    float x,y;
}STRVEC;

void vecToUnit(STRVEC *str)
{
    float S = sqrt(pow((*str).x, 2) + pow((*str).y, 2));
    str->x /= S;
    str->y /= S;
    return;
}


int main()
{
    STRVEC v1 = {3,4};
    vecToUnit(&v1);
    printf("%.1f %.1f\n", v1.x, v1.y);
}