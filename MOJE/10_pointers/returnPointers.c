#include <stdio.h>
#include <stdlib.h>

int* createIntArray(int size){
    int* arr = (int*)malloc(size*sizeof(int));
    if (arr==NULL){
        printf("Fail\n");
        return NULL;
    }
    for (int i=0; i<size; i++){
        arr[i] = i*2;
    }
    return arr;
}

int main(){
    int* myArray;
    int size = 5;

    printf ("before allocation myArray=%p\n", myArray);
    myArray = createIntArray(size);
    printf ("after allocation myArray=%p\n", myArray);

    if (myArray!=NULL){
        printf("Array: ");
        for (int i=0; i<size; i++){
            printf("%d ", myArray[i]);
        }
        printf("\n");
        free(myArray);
    }

    return 0;
}