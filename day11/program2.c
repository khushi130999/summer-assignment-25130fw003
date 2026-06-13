#include<stdio.h>
int max(int a , int b){
return (a>b)?a:b;
}
int main(){
    int n1 , n2, result ; 
    printf(" enter the two value:");
    scanf("%d %d" , &n1 , &n2);
    result =  max( n1 , n2);
    printf( " max : %d", result);
    return 0;

}