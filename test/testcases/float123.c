#include <stdio.h>

float add1(float);
float add2(float,float);
float add3(float,float,float);
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
   
   return add2(n+1,n-1);
}
float add2(float n,float m){

	return add3(n+1,m,n-1);
}
float add3(float n ,float m,float p){
	return n+m+p;
}