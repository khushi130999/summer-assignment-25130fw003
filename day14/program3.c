
#include <stdio.h>
int getSecondLargest(int arr[] , int n)
 {
    int largest = -1, secondLargest = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest)
            largest = arr[i];

    for (int i = 0; i < n; i++) {
        
        if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}
 }
int main() {
    int arr[] = {12, 35, 1, 10, 34, 1}; 
	int n = sizeof(arr)/sizeof(arr[0]);
  
    printf("%d\n", getSecondLargest(arr, n)); 
    return 0; 
}