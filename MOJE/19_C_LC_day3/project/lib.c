#include<string.h>
#include<stdlib.h>
#include"lib.h"

Position * average_position(Position* positions, int n_values)
{
    float sumX=0;
    float sumY=0;
    
    for (int i=0; i<n_values; i++)
    {
        sumX+=positions[i].x;
        //sumX+=positions[i].x+1; // BUG for testing
        sumY+=positions[i].y;
    }
    
    Position* averagePoint=(Position *)malloc(sizeof(Position));
    averagePoint->x=sumX/(float)n_values;
    averagePoint->y=sumY/(float)n_values;
    
    return averagePoint;
}