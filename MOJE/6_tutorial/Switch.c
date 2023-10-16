#include <stdio.h>

void switching1(int a, int b);
void switching2(int *a, int *b);

int main()
{
    int a=4;
    int b=5;

    printf("\nbefore a: %d, b: %d", a, b);

    switching1(a, b);
    printf("\nafter (pass by value) a: %d, b: %d", a, b);

    switching2(&a, &b);
    printf("\nafter (pass by reference) a: %d, b: %d", a, b);
}

//Pass by value
void switching1(int a, int b){
    int temp=a;
    a=b;
    b=temp;
    printf("\ninside (pass by value) a: %d, b: %d", a, b);
}

//Pass by reference
void switching2(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("\ninside (pass by reference) a: %d, b: %d", *a, *b);
}