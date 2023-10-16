#include <stdio.h>

int main(void){

    const float PI = 3.14;

    float r1=2.2;
    float r2=3.4;

    float area=0;

    if (r1>=r2)
    {
        area = PI*(r1*r1-r2*r2);
    }
    else
    {
        area = PI*(r2*r2-r1*r1);
    }

    printf("area of the ring %f", area);
    
}