#include <stdio.h>

int main(void){

    float radius;
    float area;

    radius = 1.2;
    
    const float PI = 3.14;
    
    //printf ("What is the radius?\n");
    // scanf ("%f", &radius);
    
    area = PI*radius*radius;

    printf ("\nArea of the circle is %f", area); //%g - (nie wyświetla zer)

    return 0;
    
}