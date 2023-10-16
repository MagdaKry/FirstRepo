#include <stdio.h>
#include <stdbool.h>

int main ()
{
   char str1 [] = {"Magdalena"};

   int size=0;
   int i=0;

   while(str1[i]!='\0')
   {
        i++;
        size+=1;
   }
   
   printf("size: %d\n", size);
   printf("first character: %c\n", str1[0]);
   printf("last character: %c\n", str1[size-1]);
   
   bool flag = false;
   
   int j=0;
   
   for(j=0; j<size;j++)
   {
        if (str1[j]=='c')
        {
            flag = true;
            break;
        }
   }
   
   if(flag)
   {
       printf("position of c: %d", j+1);
   }
   else
   {
       printf("c not found");
   }
}