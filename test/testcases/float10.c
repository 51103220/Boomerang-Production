#include <stdio.h>

float add10(float,float, int, int, float, float, int ,int,float, float);
int main()
{
   float n,m,o,p,q,k;
int a,b,c,d;
   float result;
   scanf("%d", &n);
   result = add10(n,m,a,b,o,p,c,d,q,k);
 
   printf("Sum = %ld\n", result);
 
   return 0;
}
 
float add10(float n,float m, int a, int b, float o, float p, int c, int d, float q, float k) {
   return n+m+a+b+o+p+c+d+q+k;
}
