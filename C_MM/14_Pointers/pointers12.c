#include <stdio.h>
#include <stdlib.h>

int Add(int a, int b) // CALLED FUNCTION - CALL BY VALUE
{
   int c = a + b;
   printf("Local a = %d\n", &a);
   printf("Local b = %d\n", &b);
   printf("Local c = %d\n", &c);
   return c; 
}
int Add_P(int *a, int *b) // CALLED FUNCTION - CALL BY REFERENCE
{
   int c = *a + *b;
   printf("Local a = %d\n", a);
   printf("Local b = %d\n", b);
   return c; 
}

int *Add_Heap(int *a, int *b)
{
    int *c = (int*)malloc(sizeof(int));
    *c = *a + *b;
    return c;
}

int main() // CALLING FUNCTION
{
    int a = 2, b = 4;
    int *ptr = Add_Heap(&a, &b);
    printf("Sum = %d\n", *ptr);


    //int c = Add(a,b);
    //int c = Add_P(&a,&b);
    /*    
    printf("main a = %d\n", &a);
    printf("main b = %d\n", &b);
    printf("main c = %d\n", &c);
    printf("Sum = %d", c);   
    */
 
}