#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char** split_str(char* str, char separator)
{
   char s[2]; 
   s[0] = separator;
   s[1] = '\0';
   
   int count=0;
   for (int i=0; i<strlen(str); i++)
   {
      if (str[i]==separator)
         count++;
   }
   printf("%d\n", count);

   char **array=(char**)malloc((count+1)*sizeof(char*));
   char *token;

   /* get the first token */
   token = strtok(str, s);
   int i=0;
   /* walk through other tokens */
   while(token != NULL)  
   {
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