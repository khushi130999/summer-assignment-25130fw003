#include <stdio.h>

int main() {

    int n, i, mostFrequent, maxCount = 0;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements: ", n);

    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int freq[1000] = {0}; 

    for(i = 0; i < n; i++) {

        freq[arr[i]]++;

        if(freq[arr[i]] > maxCount) {
            maxCount = freq[arr[i]];
            mostFrequent = arr[i];
        }

    }

    printf("The most frequent element is %d, occurring %d times.\n", mostFrequent, maxCount);

    return 0;

}