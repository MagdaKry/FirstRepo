#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main()
{
    char *str="programowanie w jezyku c";
    char temp[strlen(str)];
    
    char separator = ' ';
    int count=0;
    for (int i=0; i<strlen(str); i++)
    {
        if (str[i]==separator)
            count++;
    }
    printf("%d\n", count);
    
    char array[count+1][strlen(str)];

    int j=0;
    int m=0;
    for (int i=0; i<=strlen(str); i++)
    {
        if(str[i]==separator || str[i]=='\0')
        {
            int k=0;
            for (j; j<i; j++)
            {
                array[m][k]=str[j];
                printf("i=%d, j=%d, k=%d, m=%d, %c\n", i, j, k, m, str[j]);
                k++;
            }
            array[m][k]='\0';
            m++;
            j=i+1;
        }
    }

    printf("%s\n", array[0]);
    printf("%s\n", array[1]);
    printf("%s\n", array[2]);
    printf("%s\n", array[3]);

    return 0;

}