#include <stdio.h>

int main(void){

    float income = 100000;
    float rest = 0;
    float tax=0;
    
    if (income<=10000)
    {
	tax=0;
    }
    else if (income>10000 && income <=30000)
    {
        rest=income-10000;
        tax=rest*0.1;
    }
    else if (income>30000 && income <=60000)
    {
        rest=income-30000;
        tax=rest*0.3+0.1*20000;
    }
    else if (income>60000)
    {
        rest=income-60000;
        tax=rest*0.5+0.1*20000+0.3*30000;
    }
    
    printf ("tax is: %f", tax);
}