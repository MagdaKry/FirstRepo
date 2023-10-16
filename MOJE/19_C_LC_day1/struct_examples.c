/*
Create a struct Point with two float members x and y (using typedef)
set the values of members to arbitrary values and print them
*/
typedef struct Point{
    float x;
    float y;
}Point;

int main(void){

    Point p;
    p.x=1.2;
    p.y=2.4;
    printf("%f %f", p.x,p.y);
    
}


/*
Keep the same struct Point as before. 
1. Create a point p1 without specifying its member values
2. Create a Point* point_pointer and affect its value to the address of p1 with the & symbol
3. Set the members of p1 through the point_pointer variable
4. Display the members of p1 and point_pointer and check the values are the same
*/

typedef struct Point{
    float x;
    float y;
}Point;

int main(void){
    
    Point p1;
    Point* point_pointer;
    
    point_pointer=&p1;
    point_pointer->x=1.2;
    point_pointer->y=2.4;
    printf("%f %f\n", p1.x, p1.y);
    printf("%f %f", point_pointer->x, point_pointer->y);
}

/*
create a function Point* new_point(float x, float y) which creates and return a new point
If you want to test your function use the test_main function acting like a pseudo-main
*/

typedef struct Point{
    float x;
    float y;
} Point;

Point* new_point(float x, float y)
{
    Point* newP=(Point*)malloc(sizeof(Point));
    newP->x=x;
    newP->y=y;
    return newP;
}


void test_main(){
    //it is like a main for testing !
}