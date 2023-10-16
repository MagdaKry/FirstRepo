#include <stdio.h>
#include <stdlib.h>

int indexOfSeq(int x, int tab[], int size, int a)
{
    if (a >= size)
        return -1;
    if (tab[a] == x)
        return a;
    return indexOfSeq(x, tab, size, a + 1);
}

int main()
{

    int tab[] = {1, 2, 3};
    int size = sizeof(tab) / sizeof(tab[0]); // Nb of items
    printf("The size or tab is %d\n", size);

    printf("%d", indexOfSeq(3, tab, size, 0));

    return 0;
}