#include <stdlib.h>
#include <stdio.h>

/*
Make a Temperature struct with 

a float temperature member
a Position member
Create a function average_temperature(Temperature t1, Temperature t2) 
which computes the average of two temperatures struct
*/

typedef struct Point{
    float x;
    float y;
}Point;

typedef struct Temperature{
    float temperature;
    Point coordinate;
}Temperature;



float average_temperature(Temperature t1, Temperature t2)
{
    return (t1.temperature+t2.temperature)/2;
    //bug
    //return -1;
}

int main()
{
    Temperature t1;
    Temperature t2;
    t1.temperature=22;
    t1.coordinate.y=1.0;
    t1.coordinate.x=2.0;
    t2.temperature=8;
    t2.coordinate.y=4.0;
    t2.coordinate.x=3.0;

    printf("average=%f",average_temperature(t1, t2));
    if(average_temperature(t1,t2)!=15)
    {
        printf("bug in line %d", __LINE__);
    }
    return 0;
}
