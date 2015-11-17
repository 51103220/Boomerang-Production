#include <stdio.h>
long sumarray(int [], int, int[], int);
 
int main()
{
   int n, c, m, array[100],array1[100];
   long result;
 
   scanf("%d", &n);
 
   for (c = 0; c < n; c++)
      scanf("%d", &array[c]);
 
   result = sumarray(array, n,array1,m);
 
   printf("Sum = %ld\n", result);
 
   return 0;
}
 
long sumarray(int a[], int n,int b[], int m) {
   static long sum = 0;
   static long sum2 = 0; 
  for(int i =0;i<n;i++)
   sum = sum + a[i];
   for(int i=0;i<m;i++)
      sum2=sum2+b[i];
   return sum+   sum2;
}
