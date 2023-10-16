#include <stdio.h>
#include <stdlib.h>

int main()
{

    char c = '2';

    if (c >= 'A' && c <= 'Z')
        printf("%c is a capital letter", c);
    else if (c >= 'a' && c <= 'z')
    {
        printf("%c is a small letter", c);
    }
    else if (c >= '0' && c <= '9')
        printf("%c is a digit", c);

    return 0;
}