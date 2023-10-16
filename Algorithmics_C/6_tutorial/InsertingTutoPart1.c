#include <stdio.h>
#include <stdlib.h>

void insertEnd(int n, int t[], int size, int tab1[]);
void insertBeginning(int n, int t[], int size, int tab1[]);
void printArray(int size, int tab[]);
int getNumber();
char getPosition();

int main()
{

    int tab[] = {1, 2, 5, 4, 5};

    const int N = sizeof(tab) / sizeof(tab[0]); // Nb of items

    printArray(N, tab);

    int nb = getNumber();
    char pos = getPosition();

    int tab1[N + 1];

    if (pos == 'e')
    {
        insertEnd(nb, tab, N, tab1);
    }
    else if (pos == 'b')
    {
        insertBeginning(nb, tab, N, tab1);
    }

    printArray(N + 1, tab1);

    return 0;
}

    void insertEnd(int n, int t[], int size, int tab1[])
    {

        for (int i = 0; i < size; i++)
            tab1[i] = t[i];

        tab1[size] = n;
    }

    void printArray(int size, int tab[])
    {
        for (int i = 0; i < size; i++){
            printf("%d", tab[i]);
        }
        printf("\n");
    }

    void insertBeginning(int n, int t[], int size, int tab1[])
    {

        tab1[0] = n;

        for (int i = 0; i < size; i++)
            tab1[i + 1] = t[i];
    }

    int getNumber()
    {
        int nb;
        printf("What is the number you want to add?");
        scanf("%d", &nb);
        return nb;
    }

    char getPosition(){
        char c;
        printf("Choose where to add the number: e for end and b for beginning");
        scanf(" %c", &c);
        return c;
    }