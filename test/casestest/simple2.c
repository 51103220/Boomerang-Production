#include <stdio.h>
long add2(int,int);
 
int main()
{
   int n;
   int m;
	long result;
   scanf("%d", &n);
   scanf("%d",&m);
   result = add2(n,m);
   
   printf("Sum = %ld\n", result);
 
   return 0;
}
 
long add2(int n, int m) {
   
   return n+m;
}
