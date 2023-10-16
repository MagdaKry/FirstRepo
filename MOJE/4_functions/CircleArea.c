#include <stdio.h>

float areaOfCircle (float radius);

int main(void){

    float radius = 1.2;
    
    printf ("\nArea of the circle is %f", areaOfCircle(radius));

    return 0;
    
}

float areaOfCircle (float radius)
{
    const float PI = 3.14;
    float area=PI*radius*radius;
    return area;
}