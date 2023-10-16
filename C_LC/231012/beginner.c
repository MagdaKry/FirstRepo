void test_main(){
    //it is like a main for testing !

    int v1 = 1;
    float v2 = 2.2;
    double v3 = 3.3; //takes more space
    
    
    
    //array creation
    
    double v4[5]; //takes 5 times more space in memory than v2
    
    //access data from an array (or a string)
    
    v4[0] = 2; //first value of v4 will 2
    v4[1] = 3.3;//second


    printf("%g %g\n", v4[0], v4[1]);
    printf("%p %p\n", &v4[0], &v4[1]); 
    
    
    
    double *p1; //undefined adress at this point
    p1 = &v4[1]; //store the adress of v4
    
    printf("%p %p\n", &v4[1], p1); 
    //get the value -> *p1
    printf("%g", *p1);
    
    
    
}


void test_main(){
    //it is like a main for testing !
    int a = 1;
    
    printf("%d\n", a);
    //add 1 to the variable
    a = a + 1;
    
    printf("%d\n", a);
    a++;
    
    printf("%d\n", a);
    a+=1;
    
    printf("%d\n", a);
    
    //add more than one : ++
    a+=44;
  
    printf("%d\n", a);
    
    a-=10; // works also with / and *
    
    printf("%d\n", a);
    
    int array[3] ={1, 2, 3};
    int total = 0;
    for (int i = 0; i < 3; i++){
        
        total += array[i];
    }
    
    printf("%d\n", total);
    
}
