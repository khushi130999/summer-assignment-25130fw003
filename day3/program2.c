#include<stdio.h>
int main ()
{
    int i, prime, n1, n2, n;
    printf ("enter the lower number : ");
    scanf ("%d", &n1);
    printf ("ENTER THE UPPER number : ");
    scanf ("%d", &n2);
    if(n1>=2)
    {
        printf ("Prime number are : ");
        for (n = n1 + 1; n < n2; n++)
        {
            prime = 1;
            for (i = 2; i < n/2; i++)
                if (n % i == 0)
                {
  prime = 0;
                    break;
                }
            if (prime)
                printf ("\t %d", n);
        }
    }
    else
    {
        printf("Enter lower number must be greater than 1");
    }
}