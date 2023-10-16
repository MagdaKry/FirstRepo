#include <stdio.h>
#include <stdlib.h>

int Add(int a, int b)
{
    return a+b;
}

void A()
{
    printf("Hello");
}
void B(void (*ptr)()) // Function pointer as argument
{
    ptr(); //call-back function that "ptr" points to
}

int main()
{
    int c;
    int(*p)(int,int);
    /*
    p=&Add;
    c=(*p)(2,3); // dereferencing and executing the function
    printf("%d",c);
    */
    p=Add; //function will return address
    c=p(2,3);
    printf("%d\n",c);

    //void (*p1)()=A;
    void (*p1)();
    p1=A;
    B(p1);
}