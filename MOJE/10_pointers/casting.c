//https://www.i-programmer.info/programming/cc/12124-fundamental-c-pointers-cast-a-type-punning.html?start=2

#include <stdio.h>
#include <stdlib.h>

int sumHash(char byte1,char byte2,
                   char byte3,char byte4);

void main(){
    
    int myVar=12345678; // HEX: 00BC614E = 00|BC|61|4E = INT: 00|-68|97|78 = temp[3]|temp[2]|temp[1]|temp[0];
    char *temp=(char *) &myVar;
    int result=sumHash(temp[0], temp[1],
                          temp[2],temp[3]);
    printf("%d %d %d %d\n",temp[0], temp[1], temp[2], temp[3]);
    printf("%d\n",result);
}

int sumHash(char byte1,char byte2,
                   char byte3,char byte4){
    int sum=byte1+byte2+byte3+byte4;
    return sum;
}