#include <stdio.h>

long sum2recur(int,int);
int main()
{
   int n;
   long result;
   scanf("%d", &n);
   result = sum2recur(n,10);
 
   printf("Sum = %ld\n", result);
 
   return 0;
}
 
long sum2recur(int n,int m) {
   if ((n<0)&&(m<0))  return 1;
   return 3+sum2recur(n-1,m-2);
}
