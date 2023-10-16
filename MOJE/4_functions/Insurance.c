#include <stdio.h>

float insurance (float damage);

    int main(void){

    float damage = 167.90;

    printf ("damage %g - deductible %g", damage, insurance(damage));

}

float insurance (float damage)
{
    float deductible = 0.1*damage;

    if (deductible<10)
    {
        deductible = 10;
    }
  
    if (deductible>500)
    {
        deductible = 500;
    }
    
    return deductible;
    
}