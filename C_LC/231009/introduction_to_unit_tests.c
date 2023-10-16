#include <stdio.h>

float weighted_sum(float* values, float* weights, int n_values){
    //n_valules is the size of array "values" , and "weihts"
    
    float result = 0;
    
    for (int i = 0; i < n_values; i++){
        
        result = result + values[i] * weights[i];
        
    }
    
    return result;
    
}

int test_weighted_sum(){

  // test scenario
  
  //array1 -> [1., 1., 1.]
  //weights1 -> [0, 1, 0] 
  //expected result if function works : 1*0 + 1* 1 + 1*0 = 1

  float values[3];
  values[0] = 1;
  values[1] = 1;
  values[2] =1;
  
  float weights[3];
  weights[0] = 0;
  weights[1] = 1;
  weights[2] = 0;
  
  float actual_result = weighted_sum(values, weights, 3);
  if (actual_result != 1){
    printf("BUGGGGGGGGGGGG SOMEWHERE IN WEIGHT_sum"); 
  }
  
  
}

int main() {
  
  test_weighted_sum();
}