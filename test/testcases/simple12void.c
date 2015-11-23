#include <stdio.h>

long add1(int);
long add2(int, int);
void printscreen(char* );
int main()
{
   int n;
   long result;
   scanf("%d", &n);
   result = add1(n);
 
   printf("Sum = %ld\n", result);
 
   return 0;
}
 
long add1(int n) {

   	
   return add2(n+1,n-1);
}
long add2(int n, int m){
   printscreen("Helloworld");
   return n+m;
}
void printscreen(char* str ){
	printf("%s\n",str);
	return ;
}
