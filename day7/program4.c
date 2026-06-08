#include <stdio.h>
#include <math.h>

int reverse(int num) {
   if (num == 0) 
       return 0;
   int digits = (int)log10(num); 
   return (num % 10) * pow(10, digits) + reverse(num / 10);
}
int main() {
   int num, rev;
   printf("Enter a number: ");
   scanf("%d", &num);
   rev = reverse(num);
   printf("Reversed number: %d\n", rev);
   return 0;
}