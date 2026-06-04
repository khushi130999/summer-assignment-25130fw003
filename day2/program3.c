#include <stdio.h>
int productOfDigits(int num) {
   int product = (num == 0) ? 0 : 1;
   while (num != 0) {
       product *= (num % 10);
       num /= 10;
   }
   return product;
}
int main() {
   int number;
   printf("Enter a number: ");
   scanf("%d", &number);
   printf("Product of digits = %d\n", productOfDigits(number));
   return 0;
}