#include <stdio.h>
#include <stdlib.h>

void A()
{
    printf("Hello");
}
void B(void (*ptr)()) // Function pointer as argument
{
    ptr(); // call-back function that "ptr" points to
}
int main()
{
    void (*p)();
    p = A;
    B(p); // B(A); A is call-back function
}