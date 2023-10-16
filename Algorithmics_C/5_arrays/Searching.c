#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(){

int tab[]={1,2,3,4,5};

//int tab[5]= {1,2,3,4,5};

int nb= 0;
bool found=false;


int size= sizeof(tab)/sizeof(tab[0]); //Nb of items

printf("Nb of elements:%d\n",size);

for(int i =0; i<size;i++){
    if(tab[i]==nb){
    printf("%d is found at position %d",nb,i);
    found=true;
    break;
    }
}
if(!found)printf("%d is not found in the tab",nb);



return 0;

}