#include<stdio.h>
#include<stdlib.h>

int main(){

int tab[]={1,2,3,4};

int tab1[]={5,6,7,8,9};



int size= sizeof(tab)/sizeof(tab[0]); //Nb of items
printf("Nb of elements of tab:%d\n",size);


int size1= sizeof(tab1)/sizeof(tab1[0]); //Nb of items
printf("Nb of elements:%d\n",size1);

int tab2[size+size1];

for(int i=0;i<size;i++)
tab2[i]= tab[i];

for (int i = size; i < size+size1; i++)
tab2[i]=tab1[i-size];

for(int i =0; i<size+size1;i++)
printf("%d ",tab2[i]);



    return 0;
}