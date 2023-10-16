#include <stdio.h>

void printArray(int size, int tab[]);
int getNumber(char message[]);
char getPosition();
void insertEnd(int n, int t[], int size, int tab1[]);
void insertBeginning(int n, int t[], int size, int tab1[]);

int main()
{

    const int N = getNumber("Give me a number for Dimension");
    int tab[N];

    for (int i = 0; i < N;i++){
        tab[i] = getNumber("Give me an element of the array");
    }

    printArray(N, tab);

    int nb = getNumber("Give me the number to insert");
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
    printArray(N+1, tab1);
}

void printArray(int Size, int Tab[])
{

    for (int i = 0; i < Size; i++)
    {
        printf("%d", Tab[i]);
    }
    printf("\n");
}

int getNumber(char message[])
{

    int nb;
    printf(message);
    scanf("%d", &nb);
    return nb;
}

char getPosition()
{
    char c;
    printf("Choose where to add the number: 'e' for end and 'b' for beginning");
    scanf(" %c", &c);
    return c;
}

void insertEnd(int n, int t[], int size, int tab1[])
{

    for (int i = 0; i < size; i++)
    {
        tab1[i] = t[i];
    }

    tab1[size] = n;
}

void insertBeginning(int n, int t[], int size, int tab1[])
{

    tab1[0] = n;

    for (int i = 0; i < size; i++)
    {
        tab1[i + 1] = t[i];
    }
}