#include <stdbool.h>
#include <stdio.h>

bool isPrime(int n);

int main(void){

int n=25741; // 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97

    if (isPrime(n)==true)
    {
        printf ("%d is prime\n", n); 
    }
    else
    {
        printf ("%d is not prime\n", n); 
    }
}

bool isPrime(int n)
{
    bool flag=false;
    int i;

    if (n<=1)
    {
        //printf ("%d is not prime\n", n); 
        flag=false;
    }
    else
    {
        i=n-1;
    
        while (n%i!=0 && i>1)
        {
            i--;
        }
        if (i==1)
        {
            //printf ("%d is prime\n", n); 
            flag=true;
        }
        else
        {
            //printf ("%d is not prime\n", n); 
            flag=false;
        }
    }

	return flag;
}