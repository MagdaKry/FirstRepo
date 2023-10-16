#include <stdio.h>
#include <stdlib.h>

int A[]={34,5,67,4,37,23,4,8,67,10};
int n=sizeof(A)/sizeof(int);

int largest_element(int A[], int size);
void reverse(int A[], int size);
int sum (int A[], int size);
void swap(int A[], int size, int pos1, int pos2);

int main()
{
    for (int i=0; i<n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\nMax of A: %d", largest_element(A, n));
    printf("\nSum of A elements: %d", sum(A, n));

    int pos1=3;
    int pos2=8;
    printf("\nA after swapping elements at %d and %d positions\n", pos1, pos2);
    swap(A,n,pos1,pos2);
    for (int i=0; i<n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\nSwapped A after reversing elements\n");
    reverse(A,n);
    for (int i=0; i<n; i++)
    {
        printf("%d ", A[i]);
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