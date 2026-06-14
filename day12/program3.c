#include <stdio.h>
int fib(int n) {
   int a = 0, b = 1, c, i;
   if (n == 0)
       return a;
   for (i = 2; i <= n; i++) {
       c = a + b;
       a = b;
       b = c;
   }
   return b;
}
int main()
 {
   int n;
   printf("Enter n: ");
   scanf("%d", &n);
   printf("%dth Fibonacci number is %d\n", n, fib(n));
   return 0;
}