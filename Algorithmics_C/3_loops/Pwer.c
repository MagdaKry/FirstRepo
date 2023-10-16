#include <stdio.h>

/*int puissance(int pNb, int pPuissance)
{
    if (pPuissance == 0 && pNb == 0)
    {
        return -1;
    }
    else
    {
        if (pPuissance == 0)
            return 1;
        else if (pPuissance == 1)
            return pNb;
        else
        {
            int vPuiss = pNb;
            for (int i = 1; i < pPuissance; i++)
            {
                vPuiss = vPuiss * pNb;
            }
            return vPuiss;
        }
    }
}

int main()
{
    int power = puissance(6, 2);
    printf("%d", power);

    return 0;
}*/

#include <stdio.h>

int main()
{

    // power

    int nb;
    int power;

    printf("give me a number and a power");
    scanf("%d %d", &nb, &power);

    if(nb==0 && power==0){
        printf("Indeterminate");
    }
    else{

        int result = 1;

        for (int i = 0; i < power; i++)
        {
            result = result * nb;
        }

        printf("%d", result);
    }

    
    return 0;
}