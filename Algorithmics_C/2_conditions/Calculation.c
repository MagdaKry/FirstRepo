#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{

    int nb1 = 5;
    int nb2 = 7;

    char op = '*';

    printf("Give me two numbers");
    scanf("%d %d", &nb1, &nb2);

    printf("give me an operator");
    scanf(" %c", &op);

    int result;
    bool done = true;

    switch (op)
    {
    case '+':
        result = nb1 + nb2;
        break;
    case '-':
        result = nb1 - nb2;
        break;
    case '*':
        result = nb1 * nb2;
        break;
    case '/':
        result = nb1 / nb2;
        break;
    default:
        done = false;
        break;
    }
    if (done)
    {
        printf("%d %c %d = %d", nb1, op, nb2, result);
    }
    else
    {
        printf("Impossible to find a result");
    }
}
