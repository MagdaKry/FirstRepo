#include <string.h>
#include <stdio.h>

int main()
{
    char* str1={"magda"};
    char* str2={"marek"};
    char* str3={"krysiak"};
    char array[3][80];
    strcpy(array[0],str1);
    strcpy(array[1],str2);
    strcpy(array[2],str3);
    printf("%s\n", array[0]);
    printf("%s\n", array[1]);
    printf("%s\n", array[2]);

    return 0;

}