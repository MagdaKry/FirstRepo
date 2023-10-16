#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char** split_str(char* str, char separator)
{
   char s[2]; 
   s[0] = separator;
   s[1] = '\0';

   int i=0;
   char **array=(char**)malloc((1+i)*sizeof(char*));
   char *token;

   /* get the first token */
   token = strtok(str, s);
   *(array+i)=token;
   /* walk through other tokens */
   while(token != NULL)  
   {
      array=(char**)realloc(array,(1+i)*sizeof(char*));
      *(array+i)=token;
      printf( " %s , %s\n", token, *(array+i) );
      token = strtok(NULL, s);
      printf( " %s , %s\n", token, *(array+i) );
      printf( "%d end\n", i );
      i++;
   }
   
   return array;

}

int main()
{
   
   char str [] = "Testing-strings-breaking";
   char s = '-';
   char **array;
    
   array = split_str(str, s);
   printf( " %s\n", *array );
   printf( " %s\n", *(array+1) );
   printf( " %s\n", *(array+2) );
   
   return 0;

}