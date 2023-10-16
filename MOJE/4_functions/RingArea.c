#include <stdio.h>

const float PI = 3.14;
float ringArea (float r1, float r2);

int main(void){

    float r1=2.2;
    float r2=3.4;

    printf("area of the ring %f", ringArea(r1,r2));
    
}

float ringArea (float r1, float r2)
{
    float area=0;

    if (r1>=r2)
    {
        area = PI*(r1*r1-r2*r2);
    }
    else
    {
        area = PI*(r2*r2-r1*r1);
    }
    
    return area;
}