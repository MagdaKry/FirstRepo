#include <stdio.h>

int swap (int* p1, int* p2);

void main(){
    
    int n1 = 99;
    int n2 = 101;

    printf("variables with &:\nbefore n1=%d, n2=%d\n", n1, n2);
    swap (&n1, &n2);
    printf("after n1=%d, n2=%d\n", n1, n2);
    
    int *pn1 = &n1;
    int *pn2 = &n2;

    printf("pointers:\nbefore n1=%d, n2=%d\n", n1, n2);
    swap (pn1, pn2);
    printf("after n1=%d, n2=%d", n1, n2);
    
}


int swap (int* p1, int* p2)
{
    int temp=0;
    
    temp=*p1;
    *p1=*p2;
    *p2=temp;
}

/*
Casting Pointers as Type Punning
For low level programming the need to manipulate the bytes that make up a more complex representation is very common. One long standing way of doing the job, especially in programs that target a particular fixed architecture is to use type cast punning. It may be long standing and very common but it is also undefined behavior in C99 and C11. How to avoid using type cast punning is discussed later but it so commonly used that it is worth knowing exactly how it works.

For example, suppose a device, stream or other source of data sends you an integer value as four separate byte reads. Then you could put the data together using something like:

char *myCharPointer = (char*) malloc(100);
int *myIntPointer = (int) myCharPointer;
myCharPointer[0]=1;
myCharPointer[1]=2;
myCharPointer[2]=3;
myCharPointer[3]=4;
printf("%d \n",myIntPointer[0]);
where in this case the input bytes have been set by assignment for simplicity to 1,2,3,4 in general these values would be arbitrary. The final printf displays the four bytes as an int.

Once you have seen this sort of technique you will find many uses for it. Without knowledge of it C programs are written that involve time wasting packing and unpacking as data is moved around and modified by expressions to build up the value required.

In C data is just bit patterns and how these are interpreted is controlled by type and casts to type.

By casting a pointer you can use the memory as any type you care to.

This is often referred to as type punning.

Notice that this works with local variables as well as allocated memory.

For example:

int myVar;
char *myCharPointer = (char*) &myVar;
myCharPointer[0]=1;
myCharPointer[1]=2;
myCharPointer[2]=3;
myCharPointer[3]=4;
printf("%d \n",myVar);
This casts the pointer to int obtained using & to a pointer to char. The pointer to char looks like a char or byte array and this is how we make use of it in the following assignments. When you print myVar you will discover that its value has been changed.

The same technique can be used to pass data of one type when a function is expecting another.

For example, a common task is to form the sum or some other complex expression of say four bytes of data:

int sumHash(char bytes[4]){
    int sum=0;
    for(int i=0;i<4;i++){
        sum+=bytes[i];
    }
    return sum;
}
In practice the calculation of the “hash” would be much more complicated than just summing the values in each byte but the principle is the same.

Now suppose that you would like to compute the hash on a single int. You might start to think that the thing to do is unpack each byte of the int into a char array of the correct size but it is much simpler to use pointer casting:

int myVar=12345678;
int result=sumHash((char *) &myVar);
printf("%d\n",result);
The function is expecting a char array which is the same as a pointer to char. In the call to the function the parameter we want to pass is an int variable. To convert this to pointer to char we first convert it to pointer to int using & and then cast it to pointer to char. The function treats the four bytes occupied by the int as a char[4] array.

As long as the data you want to work with is suitably arranged in memory then you can generally treat it as any type that suits the occasion.

Even when it looks as if pointer casting cannot help it usually can.

For example, consider the problem of passing an int to the rewritten sumHash function:

int sumHash(char byte1,char byte2,
                   char byte3,char byte4){
    int sum=byte1+byte2+byte3+byte4;
    return sum;
}
Now the function needs each byte supplied as a separate parameter. Surely we now have to work on unpacking the int into four separate bytes?

The best solution is to remember that pointers are arrays:

int result=sumHash(((char *) &myVar)[0], 
                       ((char *) &myVar)[1],
                       ((char *) &myVar)[2],
                       ((char *) &myVar)[3]);
A clearer way to write this is:

char *temp=(char *) &myVar;
int result=sumHash(temp[0], temp[1],
                          temp[2],temp[3]);
Once you have a pointer to data you can access any part of it using indexing or pointer arithmetic.

To cast a variable to another type:

use & to obtain a pointer to the type

cast the pointer to the type to a pointer to the new type

do any pointer arithmetic that is necessary

dereference the pointer to obtain the type

For example to obtain the 2nd byte of myVar:

pointer to the type &myVar

cast to the new type (char*)&myVar

do pointer arithmetic ((char*)&myVar)+1 or

dereference to obtain the type *(((char*)&myVar)+1)

You can usually combine steps 3 and 4 ((char*)&myVar)[1]
*/