#include <stdio.h>

float add1(float);
float add2(float);
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
    if(n < 1) 
    	return 1;
   return 1 + add2(n-1);
}
float add2(float n){
	if (n<1)
		return 1;
	return 2 + n + add1(n-1);
}
