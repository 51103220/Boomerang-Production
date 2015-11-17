#include <stdio.h>

long add1(int);
long add2(int);
int main()
{
   int n;
   long result;
   scanf("%d", &n);
   result = add1(n);
 
   printf("Sum = %ld\n", result);
 
   return 0;
}
 
long add1(int n) {
   
   return add2(n+1);
}
long add2(int n){

	return n+2;
}
