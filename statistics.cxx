#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void random_numbers(double* array, int N);
void statistics(double* array, int N, double& m, double& v);

int main(){
  
   //initializing the random seed (initial) value for rand-command in random_numbers subfunction
   srand(time(NULL));
  
   const int N = 100;
   double p[N];
   double mean, var;
   
   random_numbers(p,N);
   statistics(p,N,mean,var);

   cout << "Mean = " << mean << endl;
   cout << "Variance = " << var << endl;
        
   return 0;
}

void random_numbers(double* array, int N){

  for(int i=0; i<N; i++){
    
    //create random double (rd) value in the range between 0 and 1
    double rd = rand()/double(RAND_MAX);
  
    //saving the random_numbers into the array
    array[i] = rd;
  }
}

/* give mean & var as references to the function
   thus the original data will be overwritten
   --> assignment said return BOTH values at the SAME time */
void statistics(double* array, int N, double& m, double& v){
  
  double sum_m = 0;
  for(int i=0; i<N; i++){
    sum_m += array[i];
  }
  m = sum_m/N;
    
  double sum_v = 0;
  for (int i=0; i<N; i++){
    sum_v += ((array[i] - m) * (array[i] - m));
  }
  v = sum_v/N;
}