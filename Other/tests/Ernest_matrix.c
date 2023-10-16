/*Write a function initialize2D (int [] [] tab) that initializes tab in such a way that for each pair (line i,column j) the corresponding case (i,j) contains the value i + j.*/
#include <stdio.h>
int getint();
int initialize2D(int i, int j, int tempmatrix[i][j]);

/*Main*/
int main(){
    int i,j;
    i=getint();
    j=getint();
    int matrix[i][j];
    //int sizei=sizeof(matrix)/sizeof(matrix[0]);
    //int sizej=sizeof(matrix[0])/sizeof(matrix[0][0]);
    initialize2D(i, j, matrix);

    for (int k=0; k<i; k++){
        for (int l=0; l<j; l++) {
            printf("%d | ",matrix[k][l]);
        }
        printf("\n");
    }

    return 0;
}

/*Functions*/
int getint(){
    int in;
    printf("Please provide an integer: ");
    scanf("%d",&in);
    return in;
}

int initialize2D(int i, int j, int tempmatrix[i][j]){
    for (int ii=0; ii<i; ii++){
        for (int ij=0; ij<j; ij++){
            tempmatrix[ii][ij]=ii+ij;
        }
    }
    return 0;
}