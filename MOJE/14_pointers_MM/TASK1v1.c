#include <stdio.h>
#include <stdlib.h>

int A[]={34,5,67,4,37,23,4,8,67,10};
const int size=sizeof(A)/sizeof(int);

int largest_element();
void reverse();
int sum ();
void swap(int pos1, int pos2);

int main()
{
    for (int i=0; i<size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\nMax of A: %d", largest_element());
    printf("\nSum of A elements: %d", sum());

    int pos1=3;
    int pos2=8;
    printf("\nA after swapping elements at %d and %d positions\n", pos1, pos2);
    swap(pos1,pos2);
    for (int i=0; i<size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\nSwapped A after reversing elements\n");
    reverse();
    for (int i=0; i<size; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
}

int largest_element()
{
    int max=A[0];
    for (int i=1; i<size; i++)
    {
        if (A[i]>max)
        {
            max=A[i];
        }
    }
    return max;
}

void reverse()
{
    int temp=0;
    
    for (int i=0; i<size/2; i++)
    {
        temp=A[i];
        A[i]=A[size-i-1];
        A[size-i-1]=temp;
    }
}

int sum ()
{
    int sum=A[0];
    for (int i=1; i<size; i++)
    {
        sum+=A[i];
    }
    return sum;
}

void swap(int pos1, int pos2)
{
    //position-1=indexOfArray;
    int temp=A[pos1-1];
    A[pos1-1]=A[pos2-1];
    A[pos2-1]=temp;
}