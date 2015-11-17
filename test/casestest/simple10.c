#include <stdio.h>
long add10(int,int,int,int,int,int,int,int,int,int);
 
int main()
{
   int n;
   int m;
	long result;
   scanf("%d", &n);
   scanf("%d",&m);
   result = add10(n,m,1,2,3,4,5,6,7,8);
   
   printf("Sum = %ld\n", result);
 
   return 0;
}
 
long add10(int n, int m,int a, int b, int c, int d, int e, int f, int g, int h) {
   
   return a+b+c+d+e+f+g+h+m+n;
}
