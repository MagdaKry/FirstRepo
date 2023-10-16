#include <stdio.h>

int perimeterOfRectangle (int l, int w);

int main(void){

    int length = 2;
    int width = 4;

    printf ("Perimeter of the rectangle is %d", perimeterOfRectangle(length, width));
    
}

int perimeterOfRectangle (int l, int w)
{
    int perimeter = 0;
    perimeter = 2 * (l + w);
    return perimeter;
}