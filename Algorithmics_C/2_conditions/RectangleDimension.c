#include<stdio.h>


int main(){

    int xA = 2;
    int xB = 3;

    int yA = 5;
    int yB = 7;

    int dim1, dim2;
    int len, width;

    if(xA > xB)
    {
        dim1 = xA - xB;
    }
    else
    {
        dim1 = xB - xA;
    }
    if (yA > yB)
    {
        dim2 = yA - yB;
    }
    else
    {
        dim2 = yB - yA;
    }

    if (xA>yA) // if(dim1>dim2)
    {
        len = dim1;
        width = dim2;
    }
    else 
    {
        len = dim2;
        width = dim1;
    }

    printf("Length : %d and width = %d", len, width);


} 