#include <stdio.h>

int lengthOfString (char str[]);
int nbOfWords (int size, char str[size]);

int main ()
{
    char str1[100];
    printf("write your string ");
    fgets(str1, sizeof(str1), stdin);
    //printf("%d",lengthOfString(str1));
    printf("%s has %d words \n", str1, nbOfWords(lengthOfString(str1), str1));
}

int lengthOfString (char str[])
{
    int size=0;
    int i=0;
    while(str[i]!='\0')
    {
        i++;
        size+=1;
    }
    return size;
}

int nbOfWords (int size, char str[size])
{
    int counter = 0;
    int i=1;

    while (i<=size)
    { 
        if ((str[i]==' ' && str[i-1]!=' ' && str[i+1]!=' ' )||(str[i]=='\0' && str[i-1]!=' '))
        {
            counter+=1;
        }
        i++;
    }

    return counter;
}