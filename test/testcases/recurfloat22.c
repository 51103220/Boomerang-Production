#include <stdio.h>

float add1(float);
float add2(float,float);
float main()
{
   float n;
   float result;
   scanf("%d", &n);
   result = add2(n,n*n);
 
   printf("Sum = %ld\n", result);
 
   return 0;
}
 
float add1(float n) {
    if(n < 1) 
    	return 1;
   return 1 + add2(n-1,n+2);
}
float add2(float n,float m){
	if (n<1)
		return 1;
	return 2 + m + add1(n-1);
}
