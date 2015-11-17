#include <stdio.h>
long calculateSum(int [], int);
 
int main()
{
   int n, c, array[100];
   long result;
 
   scanf("%d", &n);
 
   for (c = 0; c < n; c++)
      scanf("%d", &array[c]);
 
   result = calculateSum(array, n);
 
   printf("Sum = %ld\n", result);
 
   return 0;
}
 
long calculateSum(int a[], int n) {
   static long sum = 0;
 
   if (n == 0)
      return sum;
 
   sum = sum + a[n-1];
 
   return calculateSum(a, --n);
}
