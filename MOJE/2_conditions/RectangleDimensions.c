#include <stdio.h>

int main(void){

int x1=4, y1=-4, x2=-4, y2=4;
int l=0, w=0;
int temp=0;

if(x1<x2)
{   
    l=x2-x1;
    if (y1>y2) //1 x1=-10, y1=100, x2=-3, y2=0; length 100, width 7
    {
        w=y1-y2;
        printf("rectangle 1\n");
    }
    else if (y1<y2) //2 x1=0, y1=0, x2=5, y2=6; length 6, width 5
    {
        w=y2-y1;
        printf("rectangle 2\n");
    }
}
else if (x2<x1)
{
    l=x1-x2;
    if(y1>y2) //3 x1=-12, y1=0, x2=-25, y2=-4; length 13, width 4
    {
        w=y1-y2;
        printf("rectangle 3\n");
    }
    else if (y1<y2) //4 x1=4, y1=-4, x2=-4, y2=4; length 8, width 8
    {
        w=y2-y1;
        printf("rectangle 4\n");
    }
}

if (l<w)
{
    temp = l;
    l = w;
    w = temp;
}

printf("length %d, width %d", l, w);

}