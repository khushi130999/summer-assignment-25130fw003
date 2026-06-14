#include<stdio.h>
int checkpalindrome( int n){
    int rev = 0, r , temp ;
    temp = n ;
    while( n != 0)
    {
        r = n%10;
        rev = rev *10 + r;
        n = n/10;
    }
    if( rev == temp)
    return 0;
    else 
   return 1;
}
 int main()
 {
    int N ;
    printf(" enter a number");
    scanf(" %d" , &N);
    if( checkpalindrome(N) == 0)
    printf( " %d is palindrome number" , N);
 else 
 printf(" %d is not palindrome number" , N);
  return 0;
 }