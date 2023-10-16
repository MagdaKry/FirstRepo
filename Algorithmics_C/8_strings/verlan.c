#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
 
//char message[]="Hello World form nada";
char message[]= "zsdrt";


for(int i=strlen(message)-1;i>=0;i--){
   printf("%c",message[i]);
}

    return 0;
}

