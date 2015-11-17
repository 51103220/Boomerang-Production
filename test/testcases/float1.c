#include <stdio.h>

float add1(float);
int main()
{
   float n;
   float result;
   scanf("%d", &n);
   result = add1(n);
 
   printf("Sum = %ld\n", result);
 
   return 0;
}
 
float add1(float n) {
   
   return n+1.0;
}
