#include <stdio.h>

int main()
{
    int r = 5;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r - i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}