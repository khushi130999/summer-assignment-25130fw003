#include <stdio.h>
#include <string.h>
int main() {
   char str[100];
   int i;
   printf("Enter a string in uppercase: ");
   fgets(str, sizeof(str), stdin); 
   for (i = 0; str[i] != '\0'; i++) {
       if (str[i] >= 'A' && str[i] <= 'Z') {
           str[i] = str[i] + 32; 
       }
   }
   printf("Lowercase string: %s", str);
   return 0;
}