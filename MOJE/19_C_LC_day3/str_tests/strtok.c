#include <string.h>
#include <stdio.h>

char** split_str(char* str, char separator)
{
   char *token;
   char array[3][80];
    const char s[2] = "-";
   
   /* get the first token */
   token = strtok(str, s);
   strcpy(array[0],token);

   /* walk through other tokens */
   while( token != NULL ) {
      printf( " %s\n", token );
        strcpy(array[1],token);
      token = strtok(NULL, s);
      
   }
   
   char (*p)[80]=array;

   return &&array;
}

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

    char str[80] = "This is - www.tutorialspoint.com - website";
    char s=' ';

    char array2[3][80];
    &array[0][0]=split_str(str,s);

    return 0;

}

