#include <stdio.h>

int add1(int);
int add2(int);
int main()
{
   int n;
   int result;
   scanf("%d", &n);
   result = add1(n);
 
   printf("Sum = %ld\n", result);
 
   return 0;
}
 
int add1(int n) {
    if(n < 1) 
    	return 1;
   return 1 + add2(n-1);
}
int add2(int n){
	if (n<1)
		return 1;
	return 2 + n + add1(n-1);
}
