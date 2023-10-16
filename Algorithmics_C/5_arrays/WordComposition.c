#include<stdio.h>
#include<stdlib.h>

int main(){

char tab[]={'N','a','d','a'};

//int tab[5]= {1,2,3,4,5};


int size= sizeof(tab)/sizeof(tab[0]); //Nb of items

printf("Nb of elements:%d\n",size);
for(int i =0; i<size;i++)

printf("%c",tab[i]);



return 0;

}