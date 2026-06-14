#include<stdio.h>
int perfectnumber( int n){
    int i = 1, sum = 0 ;
    while( i< n)
    {
        if( n% i == 0)
        sum = sum + i;
       i++ ;
    }
      if( sum == n)
       return 0;
       else 
       return 1 ;
    
}
   int main()
   {
    int N;
    printf(" enter a number:");
    scanf(" %d" , N);
    if( perfectnumber == 0)
    printf("%d is prefect number" , N);
   else
   printf(" %d is not a prefect number" , N);
   return 0;
   }