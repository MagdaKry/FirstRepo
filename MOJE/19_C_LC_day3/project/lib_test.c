#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"lib.h"

void test_average_position(){
    //it is like a main for testing !
    Position array[3];
    array[0].x=1;
    array[0].y=2;
    array[1].x=3;
    array[1].y=4;
    array[2].x=5;
    array[2].y=6;
    
    Position* averageTest=(Position *)malloc(sizeof(Position));
    averageTest=average_position(array, 3);
    printf("%f %f", averageTest->x, averageTest->y);

    float actual_resultX =averageTest->x;
    float actual_resultY =averageTest->y;
    
    if (actual_resultX != 3 || actual_resultY != 4)
    {
        printf("BUG in line %d", __LINE__); 
    }

}

void main()
{
    test_average_position();
}