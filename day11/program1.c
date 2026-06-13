#include <stdio.h>
int add(int a, int b){
    return a + b ;
}
int main(){
int n1 , n2 , result ;
printf(" enter the two value");
scanf(" %d %d" , &n1, &n2);
result = add(n1 , n2);
printf("sum: %d" , result);
return 0;
}
