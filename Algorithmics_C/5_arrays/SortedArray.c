#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(){

int tab[]={1,2,3,4,5,0};

//int tab[5]= {1,2,3,4,5};

bool sorted= true;


int size= sizeof(tab)/sizeof(tab[0]); //Nb of items

printf("Nb of elements:%d\n",size);
for(int i =0; i<size-1; i++){
    if(tab[i]>tab[i+1]){
        sorted=false;
        break;
    }
} 

if(sorted)
printf("Array is sorted\n");
else printf("Array is not sorted");



return 0;

}