#include<stdio.h>
int main()
{
    int ch , c=0 , n500 ,n200 ,n100 , amount;
    float bal=5000;
    do
    {
        printf("welcome to my ATM \n");
        printf("enter your choice: \n");
        printf("1 show balance: \n");
        printf("2 deposite: \n");
        printf("3 withdraw :\n");
        scanf("%d" ,&ch);
        switch(ch)
        {
            case 1:
            printf("your balance is %.2f \n" ,bal);
            break;
            case 2:
            printf("enter your deposit amount \n");
            scanf(" %d" ,&amount);
            if(amount >0)
            {
                bal =  bal + amount ;
                printf("deposit successfully your bal is %.2f \n" , bal);
               
            }
    
            else{
                printf("please enter valid amount\n");
            }
            break;
            case 3:
            printf("enter your withdraw amount \n");
            scanf(" %d" ,amount);
            if(amount>0 && amount <= bal)
            {
                bal = bal - amount;
                n500 = amount/500;
                amount= amount%500;
                n200 = amount/200;
                amount= amount%200;
                n100 = amount/100;
                amount= amount%100;
                 printf("notes 500 count is %d \n" ,n500);
                  printf("notes 200 count is %d \n" ,n200 );
                   printf("notes 100 count is %d \n" ,n100 );
                    printf(" sucessfully withdraw your bal is 5.2f\n" , bal) ;    
            }
            else{
                 printf("unable to process your request\n" );
            }
            break;

        }
         printf("do you want to continue press 0 \n" );
    scanf("%d" ,&c);
    }
    while(c==0);
    printf("thank you for visit\n");
    return 0;
    
}


