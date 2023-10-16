#include<stdio.h>
#include<stdbool.h>

bool isPrime(int pNb)
{
    bool vPrime = true;
    if (pNb == 1)
        vPrime = false;
    for (int i = 2; i < pNb; i++)
    {
        if (pNb % i == 0)
        {
            vPrime = false;
            break;
        }
    }
    return vPrime;
}

int main(){

    int nb = 7;

    if (isPrime(nb)) {
            printf("%d is prime", nb);
        }
        else{
            printf("%d is not prime", nb);
        }

return 0;
}