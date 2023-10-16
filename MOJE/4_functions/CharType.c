#include <stdio.h>

void characterType(char c);

int main(void){

    char char1;
    char1 = 'A';
    
    printf("Type one character %c \n", char1);
    
    scanf ("%c", &char1);
    
    characterType(char1);
}


void characterType(char c)
{
    if (c>=48 && c<=57)
    {
        printf("Character %c is \'number\' \n", c);
    }
    else if (c>=65 && c<=90)
    {
        printf("Character %c is \'uppercase\' \n", c);
    }
    else if (c>=97 && c<=122)
    {
        printf("Character %c is \'lowercase\' \n", c);
    }
    else
    {
        printf("Character %c is \'-\' \n", c);
    }
}