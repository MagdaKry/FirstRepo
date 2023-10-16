#include <stdio.h>

int main(void){

    char char1;
    char1 = 'a';
    
    printf("Type one character %c \n", char1);
    
    scanf ("%c", &char1);
    
    if (char1>=48 && char1<=57)
    {
        printf("Character %c is \'number\' \n", char1);
    }
    else if (char1>=65 && char1<=90)
    {
        printf("Character %c is \'uppercase\' \n", char1);
    }
    else if (char1>=97 && char1<=122)
    {
        printf("Character %c is \'lowercase\' \n", char1);
    }
    else
    {
        printf("Character %c is \'-\' \n", char1);
    }
}