#include <stdio.h>

int main ()
{
   char str1[100];
   
   printf("write your string");
   scanf("%s", str1);
   
   int size=0;
   int i=0;

   while(str1[i]!='\0')
   {
        i++;
        size+=1;
   }
   
   printf("size is: %d\n", size);

   char str2[size+1];

     str2[size]='\0';

   for(int i=0; i<size; i++)
   {
        str2[size-i-1]=str1[i];
   }

   printf("%s",str2);
   printf("\n");
   
   for(int i=0; i<size; i++)
   {
        printf("%c", str2[i]);
   }

}