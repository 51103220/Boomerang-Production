#include <stdio.h>

int add1(int);
int add2(int,int);
int main()
{
   int n;
   int result;
   scanf("%d", &n);
   result = add2(n,n*n);
 
   printf("Sum = %ld\n", result);
 
   return 0;
}
 
int add1(int n) {
    if(n < 1) 
    	return 1;
   return 1 + add2(n-1,n+2);
}
int add2(int n,int m){
	if (n<1)
		return 1;
	return 2 + m + add1(n-1);
}
