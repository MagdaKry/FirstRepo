#include <stdlib.h>
#include <stdio.h>

float minimum_three_numbers(float n1, float n2, float n3)
{
    float minimum = n1;
    if (n2<minimum)
    {
        //minimum=n2;
    }
    if (n3<minimum)
    {
        minimum=n3;
    }
    return minimum;
}

void test_minimum_three_numbers()
{
    // test scenario1
    float f1=4;
    float f2=56;
    float f3=-4;
    
    float actual_result = minimum_three_numbers(f1,f2,f3);
    if (actual_result != -4)
    {
        printf("BUG in line %d", __LINE__); 
    }

    // test scenario2
    f1=0;
    f2=0;
    f3=12;
    
    actual_result = minimum_three_numbers(f1,f2,f3);
    if (actual_result != 0)
    {
        printf("BUG in line %d", __LINE__); 
    }

    // test scenario3
    f1=3;
    f2=1;
    f3=100;
    
    actual_result = minimum_three_numbers(f1,f2,f3);
    if (actual_result != 1)
    {
        printf("BUG in line %d", __LINE__); 
    }
}


void main(){
    test_minimum_three_numbers();
}