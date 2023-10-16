#include <stdio.h>

float calculator (int num1, int num2, char operation);

int main(void){

int num1=2;
int num2=3;
char operation='/';

scanf ("%d %d %c", &num1, &num2, &operation);

float result = calculator (num1, num2, operation);

printf("%d %c %d = %f", num1, operation, num2, result);
}

float calculator (int num1, int num2, char operation)
{
    float result = 0;
    switch (operation){
    case 42:
        //printf("%d", num1*num2);
        result = num1*num2;
        break;
    case 45:
        //printf("%d", num1-num2);
        result=num1-num2;
        break;
    case 43:
        //printf("%d", num1+num2);
        result=num1+num2;
        break;
    case 47:
        if (num2!=0)
        {
            //printf("%g", (float)num1/(float)num2);
            result=(float)num1/(float)num2;
        }
        else 
        {
            printf("can't divide by zero \n");
            result=-1;
        }
        break;
    default:
        printf ("wrong character \n");
        result=-1;
    }
    
    return result;
}

/*
#include <stdio.h>

float calculator (int num1, int num2, char operation);

int main(void){

int num1=2;
int num2=3;
char operation='/';

scanf ("%d %d %c", &num1, &num2, &operation);

float result = calculator (num1, num2, operation);

printf("%d %c %d = %f", num1, operation, num2, result);
}

float calculator (int num1, int num2, char operation)
{
    float result = 0;
    switch (operation){
    case 42:
        //printf("%d", num1*num2);
        return num1*num2;
        //break;
    case 45:
        //printf("%d", num1-num2);
        return num1-num2;
        //break;
    case 43:
        //printf("%d", num1+num2);
        return num1+num2;
        //break;
    case 47:
        if (num2!=0)
        {
            //printf("%g", (float)num1/(float)num2);
            return (float)num1/(float)num2;
        }
        else 
        {
            printf("can't divide by zero \n");
            return -1;
        }
        //break;
    default:
        printf ("wrong character \n");
        return -1;
    }
    
    //return result;
}
*/