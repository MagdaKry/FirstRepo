#include<stdio.h>
#include<stdlib.h>

int main(){

int tab[]={1,2,3,4,5};

int nb=6;


//int tab[5]= {1,2,3,4,5};


int size= sizeof(tab)/sizeof(tab[0]); //Nb of items

int tab1[size+1];


for(int i =0; i<size;i++)
tab1[i+1]=tab[i];

tab1[0]= nb;

for(int i =0; i<=size;i++)
printf("%d ",tab1[i]);

return 0;

}