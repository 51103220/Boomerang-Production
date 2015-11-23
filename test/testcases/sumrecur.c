#include <stdio.h>
long sumarray1(int [], int);
long sumarray2(int [], int);
int main()
{
   int n, c, array[100];
   long result;
 
   scanf("%d", &n);
 
   for (c = 0; c < n; c++)
      scanf("%d", &array[c]);
 
   result = sumarray1(array, n);
 
   printf("Sum = %ld\n", result);
 
   return 0;
}
 
long sumarray1(int a[], int n) {
   static long sum = 0;
 
  for(int i =0;i<n;i++)
   sum = sum + a[i];
   sum = sum + sumarray2(a, n-1);
   return sum;
}
long sumarray2(int a[], int n) {
   static long sum = 0;
 
  for(int i =0;i<n;i++)
   sum = sum + a[i];
   sum = sum + sumarray2(a, n-2);
   return sum;
}