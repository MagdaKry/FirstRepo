#include <stdlib.h>
#include <math.h>
#include <stdio.h>

typedef struct Position
{
    float x;
    float y;
}Position;

float distance(Position p1, Position p2)
{

    return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
}

Position* closest_positions(Position* positions, int* array_size, Position query, float maximum_distance) 
{

    Position* array_closest_positions=(Position*)malloc(*array_size*sizeof(Position));

    //printf("here\n");
    if (positions == NULL)
        return NULL;
    int i=0;
    for (int j=0;j<*array_size;j++)
    {
        //printf("FOR i=%d, j=%d \n", i,j);
        Position temp;
        temp.x=positions[j].x;
        temp.y=positions[j].y;
        float dist=distance(temp,query);
        //printf("%f", dist);
        if (dist<=maximum_distance)
        {
            array_closest_positions[i].x=positions[j].x;
            array_closest_positions[i].y=positions[j].y;
            
            //printf("IF i=%d, j=%d \n", i,j);
            //printf("x=%f, y=%f \n", array_closest_positions[i].x, array_closest_positions[i].y);

            i++;
        }
        //printf("\n\n");
    }
    *array_size=i;
    array_closest_positions=(Position*)realloc(array_closest_positions, i*sizeof(Position));
    return array_closest_positions;
}


int main()
{
    Position p1, p2, p3;
    Position query;
    p1.x=0;
    p1.y=0;
    p2.x=-3;
    p2.y=-3;
    p3.x=5;
    p3.y=5;
    query.x=2;
    query.y=2;

    Position* positions=(Position*)malloc(3*sizeof(Position));
    positions[0].x=5;
    positions[0].y=5;
    positions[1].x=-3;
    positions[1].y=-3;
    positions[2].x=0;
    positions[2].y=0;

    Position* withDistance=(Position*)malloc(sizeof(Position));
    int array_size = 3;
    int* p_size=&array_size;

    withDistance=closest_positions(positions, p_size, query, 5);
    //printf("%f", withDistance[1].x);
    
    for (int i=0; i<*p_size; i++)
    {
        Position temp;
        temp.x=withDistance[i].x;
        temp.y=withDistance[i].y;
        float dist=distance(temp,query);
        printf("distance %f, point x=%f, y=%f \n",  dist, temp.x, temp.y);
    }
    

}