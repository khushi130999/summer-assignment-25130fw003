#include <stdio.h>
int main() {
   int arr[] = {10, 10, 20, 20, 10, 30, 20, 10};
   int n = sizeof(arr) / sizeof(arr[0]);
   int visited[n];
   for (int i = 0; i < n; i++) {
       visited[i] = 0;
   }
   printf("Element Frequencies:\n");
   for (int i = 0; i < n; i++) {
       if (visited[i] == 1) continue;
       int count = 1;
       for (int j = i + 1; j < n; j++) {
           if (arr[i] == arr[j]) {
               count++;
               visited[j] = 1;
           }
       }
       printf("%d occurs %d times\n", arr[i], count);
   }
   return 0;
}