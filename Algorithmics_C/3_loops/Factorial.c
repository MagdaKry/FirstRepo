#include<stdio.h>

/*static int factoriel(int pNb)
{
    if (pNb == 0 || pNb == 1)
        return 1;
    else
    {
        int vFactoriel = pNb;
        for (int i = pNb - 1; i >= 1; i--)
        {
            vFactoriel = vFactoriel * i;
        }
        return vFactoriel;
    }
}

int main(){

    printf("%d", factoriel(5));
   
    return 0;
}*/

int main()
{

    // factorial

    int nb;

    printf("give me a positive number");
    scanf("%d", &nb);

    int factorial = 1;

    for (int i = 2; i <= nb; i++)
    {
        factorial *= i;
    }

    printf("%d", factorial);

    return 0;
}