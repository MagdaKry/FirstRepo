#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int charOccurences(char message[], char c);

    int main()
    {

        char message[] = "Hello World";

        printf("%d", strlen(message));

        char c = 'l';

        int nb = charOccurences(message, c);



        printf("%c is present %d times in message\n", c, nb);

        return 0;
    }

    int charOccurences(char message[], char c)
    {
        int nb = 0;
        for (int i = 0; i < strlen(message); i++)
        {
            if (message[i] == c)
                nb++;
        }
        return nb;
    }