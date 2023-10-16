#include <stdio.h>
#include <stdlib.h>
int main() 
{
    char str[] = "3.14";
    float fnum = atof(str);
    printf("Float: %f\n", fnum);
    fnum +=2;
    printf("Float: %f\n", fnum);
    return 0;
}