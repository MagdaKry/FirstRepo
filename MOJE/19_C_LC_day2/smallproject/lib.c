#include <stdlib.h>
#include "header.h"

Point* newPoint(float newX, float newY)
{
    Point *newP=(Point*)malloc(sizeof(Point));
    newP->x=newX;
    newP->y=newY;

    return newP;
}