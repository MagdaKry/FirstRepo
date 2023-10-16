#include <stdio.h>

int main(void){

int n=29;
int i;

    if (n<=1)
    {
        printf ("%d is not prime\n", n); 
    }
    else
    {
        i=n-1;
        /*
        while (n%i!=0 && i>1)
        {
            i--;
        }
        if (i==1)
        {
            printf ("%d is prime\n", n); 
        }
        else
        {
            printf ("%d is not prime\n", n); 
        }
        */

	    while (i>1)
        {
		    if (n%i==0) 
		    {
			    printf ("%d is not prime\n", n); 
			    break;
		    }
            i--;
        }
        if (i==1) 
        {
            printf ("%d is prime\n", n);
        }
	
    }

}


