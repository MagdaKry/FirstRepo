#include<stdio.h>

int main(){

    // double tab[8]={10.5,14,8,15.5,19,13,12}; // Array containing the grades
    float tab[8] = {10, 10, 10, 10, 10, 10, 10, 10}; // Array containing the grades

    float max, min, sum = 0.0;
    int i;

    // Initialize max and min with the first grade
    max = min = sum = tab[0];

    // Calculate max, min, and sum
    for (i = 1; i < 8; i++)
    {
        if (tab[i] > max)
        {
            max = tab[i];
        }
        if (tab[i] < min)
        {
            min = tab[i];
        }
        sum += tab[i];
    }

    // Calculate the average
    float average = sum / 8;

    // Display the results
    printf("Maximum grade: %.2f\n", max);
    printf("Minimum grade: %.2f\n", min);
    printf("Class average: %.2f\n", average);

    return 0;
}
