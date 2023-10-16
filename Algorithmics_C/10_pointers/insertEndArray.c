#include <stdio.h>
#include <stdlib.h>

int* insertEnd(int n, int *t, int *size);

void printArray(int size, int *tab);

int main()
{
    int *tab = (int *)malloc(5 * sizeof(int));
    tab[0] = 1;
    tab[1] = 2;
    tab[2] = 5;
    tab[3] = 4;
    tab[4] = 5;

    int N = 5; // Initial number of items
    int nb = 6;

    printArray(N, tab);
    tab=insertEnd(nb, tab, &N);
    printArray(N, tab);

    free(tab); // Don't forget to free the dynamically allocated memory

    return 0;
}

int* insertEnd(int n, int *t, int *size)
{
    //*size = *size + 1;
    int *newPtr = (int *)realloc(t, *size * sizeof(int));

    if (newPtr != NULL)
    {
        for (int i = 0; i < *size;i++){
            *(newPtr + i) = *(t + i);
        }
        *(newPtr + *size) = n;
        *size += 1;
        // t = newPtr;
        return newPtr;
        //(*t)[*size - 1] = n; // Insert the new element at the end
    }
}

void printArray(int size, int *tab)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
}
