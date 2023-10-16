#include <stdio.h>

int main(void){

float damage = 167.90;
float deductible = 0.1*damage;

if (deductible<10)
{
    deductible = 10;
}
  
if (deductible>500)
{
    deductible = 500;
}

printf ("damage %g - deductible %g", damage, deductible);

}