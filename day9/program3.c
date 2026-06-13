#include<stdio.h>
int main()
{
    int r = 5;
    char ch = 'A';
     for( int i = 1 ; i <= r ; i++)
    {
      for( int j = 1 ; j <= i ; j++)
        {
          printf(" %c" , ch);
        }
        printf("\n");
       ch++ ;
    }
}