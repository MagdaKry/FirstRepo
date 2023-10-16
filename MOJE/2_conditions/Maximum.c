#include <stdio.h>

int main(void){

    int num1=1;
    int num2=0;
    int num3=-25;
    int num4=1;
    
    int max=0;
    
    printf("Type four numbers: \n"); 

    scanf("%d %d %d %d", &num1, &num2, &num3, &num4);
  
    max=num1;
    
    if (num1>=num2)
    {
        if (num1>=num3)
        {
            if (num1>=num4)
            {
        
            }
            else
            {
                max=num4;
            }
        }
        else
        {
            max=num3;
            if (num3>=num4)
            {
        
            }
            else
            {
                max=num4;
            }
        }
    }
    else 
    {
        max=num2;
        if (num2>=num3)
        {
            if (num2>=num4)
            {
        
            }
            else
            {
                max=num4;
            }
        }
        else
        {
            max=num3;
            if (num3>=num4)
            {
        
            }
            else
            {
                max=num4;
            }
        }
    }
    
	/*
	max=num1;

	if (num2>max)
	{
		max=num2;
	}

	if (num3>max)
	{
		max=num3;
	}

	if (num4>max)
	{
		max=num4;
	}
  	*/

    printf("Maximum number of four values is %d \n", max);
    
    return 0;
    
}