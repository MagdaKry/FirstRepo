#include <stdio.h>
void increment(int a){
    a = a + 1;
    printf("local &a = %d\n",&a);
    printf("local a = %d\n",a);
}
void increment_p(int *p){
    *p = *p + 1;
    printf("local p = %d\n",p);
    printf("local &p = %d\n",&p);
    printf("local *p = %d\n",*p);
}
void main(){
    int a = 4;
    increment(a);
    printf("main &a = %d\n",&a);
    printf("main a = %d\n",a);
    increment_p(&a);
    printf("main (call by reference) a = %d\n",a);
}