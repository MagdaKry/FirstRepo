#include <stdio.h>
#include <stdlib.h>

int main() {
  // Create an integer variable that will store the number we get from the user
  int myNum1;
  int myNum2;
  char myChar;

  // Ask the user to type a number
  printf("Type two numbers and character and press enter: \n"); 

  // Get and save the number the user types
  scanf("%d %d %c", &myNum1, &myNum2, &myChar);

  // Print the number the user typed
  printf("Your number is: %d and %d and character %c", myNum1, myNum2, myChar);

  float radius;
  float area;

  radius = 1.2;
    
  const float PI = 3.14;
    
  printf ("\nWhat is the radius?\n");
  scanf ("%f", &radius);
    
  area = PI*radius*radius;

  printf ("Area of the circle is %f", area);

  //getchar();

  return 0;
}