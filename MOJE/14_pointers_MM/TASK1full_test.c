#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int A[]={34,5,67,4,37,23,4,8,67,10};
int n=sizeof(A)/sizeof(int);

int largest_element(int A[], int size);
void reverse(int A[], int size);
int sum (int A[], int size);
void swap(int A[], int size, int pos1, int pos2);
int remove_duplicates(int A[], int size);
void sort_ascending(int A[], int size);

int main()
{
    for (int i=0; i<n; i++)
    {
        printf("%d ", A[i]);
    }

    /*
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

    printf("\nSwapped and reversed A after removing duplicates\n");
    int n_new=remove_duplicates(A,n);
    for (int i=0; i<n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\nArray B - values from A without zeros\n");
    int B[n_new];
    for (int i=0; i<n_new; i++)
    {
        B[i]=A[i];
        printf("%d ", B[i]);
    }
    */

    printf("\nA in ascending order\n");
    sort_ascending(A,n);
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

int remove_duplicates(int A[], int size)
{
    //Declared static array can't be resized
    //so I put value zero in place of removed duplicates 
    //and then I move those zeros to the end of array.
    //I return new size to create another array if needed.

    for (int i=0; i<size; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            if (A[j]==A[i])
            {
                A[j]=0;
            }
        }
    }
    
    int temp[size];
    int j=0;
    int k=0;

    for (int i=0; i<size; i++)
    {
        if (A[i]==0)
        { 
            temp[size-1-k]=0;
            k++;
            continue;
        }
        else
        {
            temp[j]=A[i];
            j++;
        }
        
    }
    for (int i=0; i<size; i++)
    {
        A[i]=temp[i];
    }

    return size-k;
}

void sort_ascending(int A[], int size)
{
    bool change = false;

    while(change==false)
    {
        change=true;
        for (int i=0; i<size-1; i++)
        {
            for (int j=i; j<size-1; j++)
            {
                if(A[j]>A[j+1])
                {
                    int temp=A[j];
                    A[j]=A[j+1];
                    A[j+1]=temp;
                    change=false;
                    //printf("%d", A[j]);
                }
            }
        }
    }
}