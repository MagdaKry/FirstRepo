#include <stdio.h>
#include <ctype.h>

int lengthOfString (char str[]);
int nbOfWords (int size, char str[size]);
void acronym (int size1, char str1[size1], int size2, char str2[size2]);

int main ()
{
    char str1[100];
    printf("write your string ");
    fgets(str1, sizeof(str1), stdin);
    //printf("%d",lengthOfString(str1));
    int words=nbOfWords(lengthOfString(str1),str1);
    printf("%s has %d words \n", str1, words);
    char str2[words];
    acronym(lengthOfString(str1), str1, words, str2);
    printf("acronym of %s is %s", str1, str2);
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

void acronym (int size1, char str1[size1], int size2, char str2[size2])
{
    int counter = 0;
    int i=0;

    str2[0]=toupper(str1[0]);
    counter = 1;
    i=1;

    while (i<size1 && counter<size2)
    { 
        if ((str1[i]==' ' && str1[i-1]!=' ' && str1[i+1]!=' ' ))
        {
            str2[counter]=toupper(str1[i+1]);
            counter+=1;
        }
        i++;
    }
    str2[counter]='\0';

}