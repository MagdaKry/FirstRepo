#include<stdio.h>

float operation(int, int,char);

int main(){

    int a = 5;
    int b = 4;

    char c = '/';

    float result = operation(a, b, c);

    printf("%d%c%d=%f", a, c, b, result);
}

float operation(int nb1, int nb2, char op){

    switch (op)
    {
    case '+':
        return nb1 + nb2;
       // break;
    case '-':
        return nb1 - nb2;
       // break;
    case '*':
        return nb1 * nb2;
       // break;
    case '/':
        return (float)nb1 / nb2;
        //break;
    default:
        return 501;
    }
}