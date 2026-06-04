#include <stdio.h>
int main(){
    int n, sum = 0, d , temp ;
    printf("enter the number");
    scanf("%d" , &n);
    temp = n;
    while(n > 0)
    {
        d = n % 10;
        sum = sum + d * d * d ;
        n = n/10;
    }
    if(sum == temp)
    printf(" number is armstrong");
else
printf("number is not armstrong");
return 0;
}