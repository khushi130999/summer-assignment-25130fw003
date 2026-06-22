#include <stdio.h>
int findLength(char *str) {
   int length = 0;
   while (str[length] != '\0') {
       length++;
   }
   return length;
}
int main() {
   char str[100];
   printf("Enter a string: ");
   fgets(str, sizeof(str), stdin);

   int len = findLength(str);
   if (str[len - 1] == '\n') {
       str[len - 1] = '\0';
       len--;
   }
   printf("Length of the string: %d\n", len);
   return 0;
}