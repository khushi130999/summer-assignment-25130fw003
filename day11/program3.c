#include<stdio.h>
int checkprime(int n){
    for( int i = 2; i< n; i++){
        if( n % i == 0){
            return 0;
        }
    }
    return 1;
}
int main(){ 
    int a ;
    printf(" enter a digit :");
    scanf(" %d" , &a);
    if( checkprime(a))
    printf("yes");
else
printf("no");
return 0;
}