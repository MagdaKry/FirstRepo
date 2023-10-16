#include<stdio.h>
#include<stdbool.h>

int main(){

    int xA = 2;
    int yA = 5;

    int xB = 3;
    int yB = 7;

    int xP = 1;
    int yP = 6;

    bool xPIn = false;
    bool yPIn = false;

    if (xA > xB)
    {
        if (xP >= xB && xP <= xA)
        {
            xPIn = true;
        }
    }
    else
    {
        if (xP >= xA && xP <= xB)
        {
            xPIn = true;
        }
    }

    if (yA > yB)
    {
        if (yP >= yB && yP <= yA)
        {
            yPIn = true;
        }
    }
    else
    {
        if (yP >= yA && yP <= yB)
        {
            yPIn = true;
        }
    }

    if (xPIn && yPIn)
        printf("Point is in rectangle");
    else
        printf("Point is not in rectangle");
}