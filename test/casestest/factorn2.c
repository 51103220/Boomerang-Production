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
   if (n<3)  return 1;
  else
   return factor(n-1)+factor(n-2)+factor(n-3);
}
