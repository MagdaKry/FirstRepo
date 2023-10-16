#include<stdio.h>

float areaCircle(float r); // declaration

int main()
{

    float radius;

    printf("Give me a radius");
    scanf("%f", &radius);

    float area= areaCircle(radius);


    printf("The area of the circle: %g", area);

    return 0;
}

float areaCircle(float r) //definition
{
    const float PI = 3.14;

    float area = PI * r * r;

    return area;
}