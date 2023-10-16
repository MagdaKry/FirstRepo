#include<stdio.h>
#include<stdlib.h>

void insertEnd(int n, int t[],int size);
void insertBeginning(int n, int t[], int size);


int main()
{

    int tab[] = {1, 2, 5, 4, 5};

    int nb = 3;

    int size = sizeof(tab) / sizeof(tab[0]); // Nb of items
    printf("Nb of elements:%d\n", size);

    // int tab[5]= {1,2,3,4,5};

    //int tab1[size + 1];
    insertEnd(nb, tab, size);
    printf("\n");
    insertBeginning(10, tab, size);

    return 0;
}



void insertEnd(int n, int t[],int size){

    /*int size = sizeof(t) / sizeof(t[0]); // Nb of items
    printf("Nb of elements:%d\n", size);*/

    int tab1[size + 1];

    for (int i = 0; i < size; i++)
        tab1[i] = t[i];

    tab1[size] = n;

    for (int i = 0; i <= size; i++)
        printf("%d", tab1[i]);

    
}


void insertBeginning(int n, int t[], int size){

    int tab1[size + 1];

    tab1[0] = n;

    for (int i = 0; i < size; i++)
        tab1[i + 1] = t[i];

        for (int i = 0; i <= size; i++)
        printf("%d", tab1[i]);
}