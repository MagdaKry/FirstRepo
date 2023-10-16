#include<stdio.h>
#include<stdbool.h>

bool isOdd(int nb);

int main(){

    int nb = 5;
    bool b = isOdd(nb);



    if(isOdd(nb)){
        printf("%d is odd",nb);
    }else{
        printf("%d is not odd", nb);
    }


}

bool isOdd(int nb){
    if (nb % 2 != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

