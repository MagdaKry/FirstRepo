/*
+ Create inside a folder “smallproject” a header.h file
+ Create a struct inside it (like Point struct)
+ create a file main.c which includes header.h with double quotes and #include
+ use your struct in the main and print its member values
+ create a file lib.c which also includes the header.h file and make a simple function using your struct
+ in your main try use to the function defined in lib.c and make it work
*/

#include "header.h"
//#include "lib.c"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    Point *newP=(Point*)malloc(sizeof(Point));
    newP->x=1.2;
    newP->y=2.4;
    printf("p=(%g,%g)\n",newP->x,newP->y);

    Point *newP_funct=newPoint(3.6,4.8);
    printf("p_func=(%g,%g)",newP_funct->x,newP_funct->y);

    return 0;
}