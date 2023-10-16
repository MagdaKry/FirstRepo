/*
int main(void){

    char tab[]={'M','a','g','d','a'};
    
    int n = sizeof(tab)/sizeof(tab[0]);//sizeof(char);
    
    for (int i=0; i<n; i++)
    {
        printf ("%c", tab[i]);
    }

}
*/

#include <stdbool.h>
#include <stdio.h>

void word(char t[], int size);

int main(void){

    char tab[]={'M','a','g','d','a'};
    int n = sizeof(tab)/sizeof(tab[0]);//sizeof(char);
    word(tab, n);
}

void word(char t[], int size)
{
    for (int i=0; i<size; i++)
    {
        printf ("%c", t[i]);
    }
}