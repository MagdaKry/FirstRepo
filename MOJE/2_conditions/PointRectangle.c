#include <stdio.h>

int main(void){

int x1=-10, y1=100, x2=-3, y2=0;
int p1=-5, p2=67;

if(x1<x2)
{   
    
    if (y1>y2) //1 x1=-10, y1=100, x2=-3, y2=0
    {
        if (x1<=p1&&p1<=x2 && y1>=p2&&p2>=y2)
        {
            printf("point is within rectangle 1"); // p1=-5, p2=67;
        }
        else
        {
            printf("point is outside the rectangle 1"); //p1=-1, p2=23;
        }
    }
    else if (y1<y2) //2 x1=0, y1=0, x2=5, y2=6
    {
        if (x1<=p1&&p1<=x2 && y1<=p2&&p2<=y2)
        {
            printf("point is within rectangle 2"); //p1=3, p2=6;
        }
        else
        {
            printf("point is outside the rectangle 2"); //p1=-1, p2=-1;
        }
    }
}
else if (x2<x1)
{
    
    if(y1>y2) //3 x1=-12, y1=0, x2=-25, y2=-4
    {
        if (x1>=p1&&p1>=x2 && y1>=p2&&p2>=y2)
        {
            printf("point is within rectangle 3"); //int p1=-25, p2=-2;
        }
        else
        {
            printf("point is outside the rectangle 3"); //int p1=0, p2=0;
        }
    }
    else if (y1<y2) //4 x1=4, y1=-4, x2=-4, y2=4
    {
        if (x1>=p1&&p1>=x2 && y1<=p2&&p2<=y2)
        {
            printf("point is within rectangle 4"); //p1=0, p2=0;
        }
        else
        {
            printf("point is outside the rectangle 4"); //p1=-5, p2=1;
        }
    }
}


}