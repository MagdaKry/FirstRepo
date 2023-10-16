#include <stdio.h>
void reverseTab(int tab[], int size);

int main()
{

    int tab[] = {1, 2, 3, 4, 5};

    int size = sizeof(tab) / sizeof(tab[0]);

    reverseTab(tab, size);

    for (int i = 0; i < size; i++)
    {
        printf("%d", tab[i]);
    }
}

void reverseTab(int tab[], int size)
{

    for (int i = 0; i < size/2; i++)
    {

        int temp = tab[i];
        tab[i] = tab[size - 1 - i];
        tab[size - i-1] = temp;
        printf("switch elements %d and %d\n", i, size - 1 - i);
    }
}