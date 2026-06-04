#include <stdio.h>
int main() {
  int n, rev = 0, r, n1;
    printf("Enter an integer: ");
    scanf("%d", &n);
    n1 = n;

    while (n != 0) {
        r = n % 10;
        rev = rev * 10 + r;
        n /= 10;
    }

    if (n1 == rev)
        printf("%d is a palindrome.",n1);
    else
        printf("%d is not a palindrome.", n1);

    return 0;
}