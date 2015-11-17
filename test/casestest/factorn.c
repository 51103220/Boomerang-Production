#include <stdio.h>

long factor(int);
int main()
{
   int n;
   long result;
   scanf("%d", &n);
   result = factor(n);
 
   printf("Sum = %ld\n", result);
 
   return 0;
}
 
long factor(int n) {
   if (n==1)  return 1;
   return n*factor(n-1);
}
