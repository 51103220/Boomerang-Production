#include <stdio.h>

long add1(int);
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
   	printscreen("Helloworld");
   return n+1;
}
void printscreen(char* str ){
	printf("%s\n",str);
	return ;
}
