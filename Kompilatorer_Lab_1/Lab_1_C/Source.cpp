#include <stdio.h>  
#include <stdlib.h>

int factorial(int n) {
  if (n == 0)
    return 1;
  else
    return n * factorial(n - 1);
}

#define FACTORIAL(n) ((n) == (0)? (1) : (n)*(factorial(n-1))));

int main ()
{
	printf("%d", FACTORIAL(2);
	getchar();
}