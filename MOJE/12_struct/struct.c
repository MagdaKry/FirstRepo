#include <stdio.h>
#include <string.h>

struct Person
{
    int ID;
    char gender;
    char name[10];
};

int main()
{
    struct Person s1;
    s1.ID = 1;
    s1.gender='M';
    strcpy(s1.name, "John");

    struct Person s2 = {2, 'W', "Gosia"};

    printf("ID: %d, Gender: %c, Name: %s.", s1.ID, s1.gender, s1.name);
    printf("\nID: %d, Gender: %c, Name: %s.", s2.ID, s2.gender, s2.name);
  
    struct Person s3;
    s3 = s2;
    printf("\nID: %d, Gender: %c, Name: %s.", s3.ID, s3.gender, s3.name);
    s2.ID = 22;
    printf("\nID: %d, Gender: %c, Name: %s.", s2.ID, s2.gender, s2.name);

    return 0;
}