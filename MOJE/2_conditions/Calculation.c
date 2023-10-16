#include <stdio.h>

int main(void){

int num1=2;
int num2=3;
char operation='*';

scanf ("%d %d %c", &num1, &num2, &operation);

switch (operation){
    case 42:
        printf("%d", num1*num2);
        break;
    case 45:
        printf("%d", num1-num2);
        break;
    case 43:
        printf("%d", num1+num2);
        break;
    case 47:
        if (num2!=0)
        {
            printf("%g", (float)num1/(float)num2);
        }
        else 
        {
            printf("can't divide by zero");
        }
        break;
    default:
        printf ("wrong character");
}
    
}