#include <stdio.h>
#include <string.h>
void reverseString(char *str) {
   int left = 0;
   int right = strlen(str) - 1;
   char temp;
   while (left < right) {
       
       temp = str[left];
       str[left] = str[right];
       str[right] = temp;
       left++;
       right--;
   }
}
int main() {
   char str[100] = "hello";
   reverseString(str);
   printf("Reversed String: %s\n", str);
   return 0;
}