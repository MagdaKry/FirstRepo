#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int GlobalA[]={34,5,67,4,37,23,4,8,67,10};
const int n=sizeof(GlobalA)/sizeof(int);

int largest_element(int A[], int size);
void reverse(int A[], int size);
int sum (int A[], int size);
void swap(int A[], int size, int pos1, int pos2);
int remove_duplicates(int A[], int size);
void sort_ascending(int A[], int size);
void print_array(int A[], int size);

int main()
{
    print_array(GlobalA, n);
    printf("\nMax of GlobalA: %d", largest_element(GlobalA, n));
    printf("\nSum of GlobalA elements: %d", sum(GlobalA, n));

    int pos1=0;
    int pos2=0;
    printf("\nGive me first position you want to swap (between %d and %d (included)):", 1, n);
    scanf("%d", &pos1);
    printf("\nGive me second position you want to swap (between %d and %d (included)):", 1, n);
    scanf("%d", &pos2);

    printf("\nGlobalA after swapping elements at %d and %d positions\n", pos1, pos2);
    swap(GlobalA,n,pos1,pos2);
    print_array(GlobalA, n);
    printf("\nSwapped GlobalA after reversing elements\n");
    reverse(GlobalA,n);
    print_array(GlobalA, n);

    printf("\nSwapped and reversed GlobalA in ascending order\n");
    sort_ascending(GlobalA, n);
    print_array(GlobalA, n);

    printf("\nSwapped and reversed GlobalA in ascending order after removing duplicates\n");
    int size_new=remove_duplicates(GlobalA, n);
    print_array(GlobalA, n);
    printf("\nArray B - values from GlobalA without zeros\n");
    int B[size_new];
    for (int i=0; i<size_new; i++)
    {
        B[i]=GlobalA[i];
    }
    print_array(B, size_new);

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
                }
            }
        }
    }
}

void print_array(int A[], int size)
{
    for (int i=0; i<size; i++)
    {
        printf("%d ", A[i]);
    }
}