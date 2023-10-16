#include <stdio.h>

void assignArray(int size, int tab[]);

int main()
{
    const int N=5;
    //int t[N];
    int t[]={0,0,0,0,0};
    printf("%p\n", t);
    printf("%p\n", &N);

    for (int i=0; i<N; i++)
    {
        printf("%d", t[i]);
    }

    assignArray(N, t);
    
    for (int i=0; i<N; i++)
    {
        printf("%d", t[i]);
    }
}

void assignArray(int size, int tab[])
{
    printf("%p\n", tab);
    printf("%p\n", &size);

    for (int i=0; i<size; i++)
    {
        tab[i]=1;
    }
}