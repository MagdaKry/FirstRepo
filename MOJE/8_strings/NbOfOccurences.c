#include <stdio.h>

int lengthOfString (char str[]);
int nbOfOccurences (int size, char str[size], char ch);

int main ()
{
    char str1[100];
    char ch1;
    printf("write your string ");
    scanf("%s", str1);
    printf("\nwrite character to find ");
    scanf(" %c", &ch1);
    printf("%c is %d times in %s", ch1, nbOfOccurences(lengthOfString(str1), str1, ch1), str1);
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

int nbOfOccurences (int size, char str[size], char ch)
{
    int counter = 0;
    for(int i=0; i<size;i++)
    {
        if (str[i]==ch)
        {
            counter+=1;
        }
    }
    return counter;
}