#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    int row = ((10+n)/2)+1;
    int space = (n/2)+5;
    for(int i=1; i<=row; i++)
    {
        for(int j=0; j<space; j++)
        {
            printf(" ");
        }
        space--;

        for(int j=0; j<i*2-1; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
            printf(" ");

        for(int j=0; j<n; j++)
            printf("*");

        printf("\n");
    }

    return 0;
}

