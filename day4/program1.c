#include<stdio.h>
int main() {
    int n,i,f1,f2,f3;
    printf("Enter the number of terms");
    scanf("%d",&n);
    f1=0;
    f2=1;
    printf("%d \t %d",f1,f2);
    for(int i=1;i<=n;i++){
        f3 = f1+f2;
        printf("\t%d",f3);
        f1 = f2;
        f2 = f3;
    }
    return 0;
}