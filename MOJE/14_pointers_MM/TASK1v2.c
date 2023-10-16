#include <stdio.h>
#include <stdlib.h>

int GlobalA[]={34,5,67,4,37,23,4,8,67,10};
const int n=sizeof(GlobalA)/sizeof(int);

int largest_element(int A[], int size);
void reverse(int A[], int size);
int sum (int A[], int size);
void swap(int A[], int size, int pos1, int pos2);

int main()
{
    for (int i=0; i<n; i++)
    {
        printf("%d ", GlobalA[i]);
    }
    printf("\nMax of GlobalA: %d", largest_element(GlobalA, n));
    printf("\nSum of GlobalA elements: %d", sum(GlobalA, n));

    int pos1=3;
    int pos2=8;
    printf("\nGlobalA after swapping elements at %d and %d positions\n", pos1, pos2);
    swap(GlobalA,n,pos1,pos2);
    for (int i=0; i<n; i++)
    {
        printf("%d ", GlobalA[i]);
    }
    printf("\nSwapped GlobalA after reversing elements\n");
    reverse(GlobalA,n);
    for (int i=0; i<n; i++)
    {
        printf("%d ", GlobalA[i]);
    }

    return 0;
}

int largest_element(int A[], int size)
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

void reverse(int A[], int size)
{
    int temp=0;
    
    for (int i=0; i<size/2; i++)
    {
        temp=A[i];
        A[i]=A[size-i-1];
        A[size-i-1]=temp;
    }
}

int sum (int A[], int size)
{
    int sum=A[0];
    for (int i=1; i<size; i++)
    {
        sum+=A[i];
    }
    return sum;
}

void swap(int A[], int size, int pos1, int pos2)
{
    //position-1=indexOfArray;
    int temp=A[pos1-1];
    A[pos1-1]=A[pos2-1];
    A[pos2-1]=temp;
}