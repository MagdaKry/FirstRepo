
typedef struct Coordinate{
    
    float x,y,z;
    
} Coordinate; //Coordinate is a custom type


void forbidden_use_of_pointer_memory(){
   
    //creating a single variale of type Coordinate;
    //type     variablename
    Coordinate c1;
    c1.x = 1;
    c1.y = 3;
    c1.z = 1.1;
    
    
    //Creating a pointer Only allocate memory for the pointer (adress)
    //Coordinate pointer
    Coordinate* coordinate_pointer1; //pointer adress is somewhere random in memory
    printf("%g\n", coordinate_pointer1->x);
    coordinate_pointer1->x = 2.2;
    printf("%g\n", coordinate_pointer1->x);
}

void test_main(){
    
    Coordinate c1; //Stack allocation
    c1.x = 1;
    c1.y = 3;
    c1.z = 1.1;
    //store the address of c1 (already allocated (STACK)
  
    Coordinate* coordinate_pointer1 = &c1; 
    
    //-> is same as deferencing the struct adress and
    //access the member
    coordinate_pointer1->x = 100;
    //both value are the same
    printf("%g same as %g\n", coordinate_pointer1->x, c1.x);
    
}

//_____________________________________________________________________________________

typedef struct Coordinate{
    
    float x,y,z;
    
} Coordinate; //Coordinate is a custom type


typedef struct SensorData{
    
    float temperature;
    float pression;
    float humidity;
    
    Coordinate position; //struct inside struct
    
} SensorData;

void test_main(){
    
    SensorData d1; //Stack allocation
    d1.temperature = 22;
    d1.pression = 0.4;
    d1.humidity = 0.7;
    //struct in struct -> access member with . 
    d1.position.x = 0.5;
    d1.position.y = 0.5;
    d1.position.z = 0.5;
    
    printf("%g\n", d1.position.z);
    
    SensorData* d_p_1 = &d1;
    
    printf(
        "temp from pointer : %g, x from pointer : %g\n", 
        d_p_1->temperature,
        d_p_1->position.x  // d_p_1 is a pointer so ->position. But ->position is not pointer ->position is a Coordinate struct
    );
    
}

//_____________________________________________________________________________________

typedef struct Coordinate{
    
    float x,y,z;
    
} Coordinate; //Coordinate is a custom type


typedef struct SensorData{
    
    float temperature;
    float pression;
    float humidity;
    
    Coordinate position; //struct inside struct
    
} SensorData;

void test_main(){
    
    SensorData* data = (SensorData*) calloc(sizeof(SensorData), 10); // Array of struct
    //data contains the address of first element
    
    data->humidity = 10;
    printf("%g\n", data->humidity); //data address is first struct value so use ->
    
    printf("%g\n", data[0].humidity); //data[0] IS the first struct so . 
    
}

//_____________________________________________________________________________________

typedef struct SensorData{
    
    float temperature;
  
    struct SensorData* next;//this member means we are using SensorData as a Linked list

} SensorData;

void stack_allocated(){
     SensorData d1, d2, d3; //stack allocated
    d1.temperature = 22;
    d2.temperature = 33;
    d3.temperature = 44;
    
    //I want a three value linked list
    //d1->d2->d3

    //d1 act as the head of LinkedList
    d1.next = &d2; //next contains addres of d2
    d2.next = &d3; //next contains address of d3

    //Let's access d3 data from d1 !!
    
    printf("%g\n", d1.next->next->temperature); //d1 is a struct so . But d1.next is pointer so -> d1->next->next is pointer!
    
    //Let's have a pointer which represents the head of Linked list
    SensorData* head = &d1; //dedicated variable to get the Head of LL
    
    printf("%g\n", head->next->next->temperature);
}

void test_main(){
    
    
    SensorData* head = (SensorData*) calloc(sizeof(SensorData), 1); //heap allocation -> data stays after end of function
    
    head->next = (SensorData*) calloc(sizeof(SensorData), 1);
    head->next->next = (SensorData*) calloc(sizeof(SensorData), 1);
    
    head->next->next->temperature = 222;
    
    printf("%g\n", head->next->next->temperature);
    
}
