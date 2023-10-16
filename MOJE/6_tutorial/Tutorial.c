#include <stdio.h>

void printArray(int size, int tab[]) ;
int getNumber(char message[]);
char getPosition();
void insertEnd(int n, int t[], int size, int tab1[]);
void insertBeginning(int n, int t[], int size, int tab1[]);
void initialize(int tab[], int size);

int main()
{
    //int tab[] = {1, 2, 5, 4, 5};
    //const int N = sizeof(tab) / sizeof(tab[0]); // Nb of items

    const int N = getNumber("\nGive me number of dimensions: ");
    int tab[N];
    
    initialize(tab,N);
    printArray(N, tab);

    int nb = getNumber("\nGive me number to insert: ");
    char p = getPosition();

    int tab1[N + 1];

    if (p == 'e')
    {
        insertEnd(nb, tab, N, tab1);
    }
    else if (p == 'b')
    {
        insertBeginning(nb, tab, N, tab1);
    }

    printArray(N + 1, tab1);
    
    return 0;
}

void printArray(int size, int tab[])
{
    for (int i = 0; i < size; i++)
    printf("%d", tab[i]);
}

int getNumber(char message[])
{
    int nb;
    printf(message);//printf("%s", message);
    scanf("%d", &nb);
    return nb;
}

char getPosition(){
    char c;
    printf("\nChoose where to add the number: e for end and b for beginning");
    scanf(" %c", &c);
    return c;
}

void insertEnd(int n, int t[], int size, int tab1[])
{
    for (int i = 0; i < size; i++){
        tab1[i] = t[i];
    }
    tab1[size] = n;
}

void insertBeginning(int n, int t[], int size, int tab1[])
{
    tab1[0] = n;
    for (int i = 0; i < size; i++)
        tab1[i + 1] = t[i];
}

void initialize(int tab[], int size){
    for (int i = 0; i < size;i++){
        tab[i] = getNumber("\nEnter element of array ");
    }
}