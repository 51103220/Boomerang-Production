#include <stdio.h>
 
int plusandminus(int);
 
main()
{
   int n;
   scanf("%d",&n);
   
      printf("%d\n", plusandminus(n));
   
 
   return 0;
}
 
int plusandminus(int n)
{
   if ( n <= 0 )
      return 0;
   else if ( n > 100 )
      return 100;
   
      return ( plusandminus(n-1) + plusandminus(n+2) );
} 
