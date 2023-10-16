#include <stdio.h>

int add (int a, int b);

//void test_main(){
int main(){
    
    int num1 = 3;
    int num2 = 5;
    
    printf ("sum of %d and %d is %d", num1, num2, add(num1, num2));
    
}

//}

int add (int a, int b)
{
    return a+b;
}