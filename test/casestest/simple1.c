#include <stdio.h>

long add1(int);
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
   
   return n+1;
}
