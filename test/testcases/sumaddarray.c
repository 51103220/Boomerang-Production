#include <stdio.h>
long sumarray(int [], int);
long add1(int); 
int main()
{
   int n, c, array[100];
   long result;
 
   scanf("%d", &n);
 
   for (c = 0; c < n; c++)
      scanf("%d", &array[c]);
 
   result = sumarray(array, n);
 
   printf("Sum = %ld\n", result);
 
   return 0;
}
 long add1(int n){
   return n+1;
 }
long sumarray(int a[], int n) {
   static long sum = 0;
 
  for(int i =0;i<n;i++)
   sum = sum + a[i];
   sum  = add1(sum);
   return sum;
}
