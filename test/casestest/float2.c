#include <stdio.h>

float add2(float,float);
int main()
{
   float n,m;
   float result;
   scanf("%d", &n);
   result = add2(n,m);
 
   printf("Sum = %ld\n", result);
 
   return 0;
}
 
float add2(float n,float m) {
   
   return n+m;
}
