#include <stdio.h>

int main()
{

    int r1 = 6;
    int r2 = 8;

    const float PI = 3.14;
    float areaRing;

    if (r1 == r2)
    {
        areaRing = 0;
    }
    else if (r1 > r2)
    {
        areaRing = PI * r1 * r1 - PI * r2 * r2;
    }
    else if (r1 < r2)
    {
        areaRing = PI * r2 * r2 - PI * r1 * r1;
    }

    printf("The area of th ring is %f", areaRing);
}