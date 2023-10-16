#include <stdio.h>

int lengthOfString (char str[]);
int nbOfVowels (int size, char str[size]);

int main ()
{
    char str1[100];
    char ch1;
    printf("write your string ");
    scanf("%s", str1);
    printf("%s has %d vowels", str1, nbOfVowels(lengthOfString(str1), str1));
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

int nbOfVowels (int size, char str[size])
{
    int counter = 0;
    for(int i=0; i<size;i++)
    {
        switch (str[i]){
        case 'a':
            counter+=1;
            break;
        case 'e':
            counter+=1;
            break;
        case 'i':
            counter+=1;
            break;
        case 'o':
            counter+=1;
            break;
        case 'u':
            counter+=1;
            break;
        case 'y':
            counter+=1;
            break;
        default:
            counter=counter;
        }
    }
    return counter;
}