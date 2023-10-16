#include <stdio.h>
#include <stdlib.h>

int Add(int a, int b)
{
    int c=a+b;
    printf("Local a=%d",&a);
    printf("\nLocal b=%d",&b);
    printf("\nLocal c=%d",&c);
    return c;
}

int Add_P(int *a, int *b)
{
    int c=*a+*b;
    printf("Local a (*p)=%d",a);
    printf("\nLocal b (*p)=%d",b);
    return c;
}
/*
int *Add_Q(int *a, int *b)
{
    int c=*a+*b;
    printf("Local a (*p_return &p)=%d",a);
    printf("\nLocal b (*p_return &p)=%d",b);
    printf("\nLocal c (*p_return &p)=%d",&c);
    return &c;
}
*/
int *Add_H(int *a, int *b)
{
    int *c=(int*)malloc(sizeof(int));
    *c=*a+*b;
    printf("Local a (*p_return &p_malloc)=%d",a);
    printf("\nLocal b (*p_return &p_malloc)=%d",b);
    printf("\nLocal c (*p_return &p_malloc)=%d",c);
    return c;
}

int main()
{
    int a=2, b=4;
    //int c=Add(a,b);
    //int c=Add_P(&a,&b);
    //int *c=Add_Q(&a, &b);
    int *c=Add_H(&a,&b);
    printf("\nMain a=%d",&a);
    printf("\nMain b=%d",&b);
    printf("\nMain c=%d",&c);
    printf("\nsum=%d",*c);

    return 0;
}