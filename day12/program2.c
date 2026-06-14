#include<stdio.h>
int armstrong( int n)
{
    int sum = 0,d , temp ;
    temp = n ;
    while( n > 0)
    {
        d = n % 10 ;
        sum  = sum + d*d *d;
        n = n/10 ;
    }
    if( sum == temp)
    return 0 ;
  else 
   return 1; 
}
int main()
{
    int N ;
    printf( " enter a number");
    scanf(" %d" ,&N );
    if( armstrong == 0)
    printf(" %d is armstrong" , N);
  else
  printf(" %d is not armstrong" ,N);
 return 0;
}