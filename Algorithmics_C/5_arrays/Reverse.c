#include<stdio.h>
#include<stdlib.h>

int main(){

int tab[]={1,2,3,4,5};

//int tab[5]= {1,2,3,4,5};


int size= sizeof(tab)/sizeof(tab[0]); //Nb of items

printf("Nb of elements:%d\n",size);
for(int i =size-1; i>=0;i--)

printf("%d\n",tab[i]);



return 0;

}