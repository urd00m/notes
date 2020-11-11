#include <stdlib.h> 
#include <stdio.h> 
#include <math.h> 

inline float InvSqrtRegular(float x) 
{ 
  return (float) (1.0f/sqrt(x)); 
} 


// my implementation - less commentary than wikipedia
// implementation
inline float InvSqrtSpecial(float x) 
{ 
  float xhalf = 0.5f*x; 
  int i = *(int*)&x; 
  i = 0x5f3759df - (i>>1); 
  x = *(float*)&i; 
  x = x*(1.5f - xhalf*x*x); 
  return x; 
} 


int main(int argc, char *argv[]) 
{ 
  volatile float value; // volatile to force compiler to recompute 
  int count; 
  int i; 

  if (argc!=4) { 
    printf("invsqrt regular|special value count\n"); 
    return 0; 
  } 

  value=atof(argv[2]); 
  count=atoi(argv[3]); 

  switch (argv[1][0]) { 

  case 'r': 
  case 'R': 
    printf("Regular: %f\n", InvSqrtRegular(value)); 
    for (i=0;i<count;i++) { 
      InvSqrtRegular(value); 
    } 
    break; 

  case 's': 
  case 'S': 
    printf("Special: %f\n", InvSqrtSpecial(value)); 
    for (i=0;i<count;i++) { 
      InvSqrtSpecial(value); 
    } 
    break; 

  default: 
    printf("invsqrt regular|special\n"); 
    return 0; 
    break; 
  } 
  return 0; 
} 

