#include<stdio.h>
#include<stdlib.h>

int main(){

int n1, n2,n3,max;

n1= 2;
n2=5;
n3=8;


if(n1>=n2)max=n1;
else max=n2;

if(max>=n3)printf("the maximum is: %d",max);
else printf("the maximum is: %d", n3);

return 0;
}