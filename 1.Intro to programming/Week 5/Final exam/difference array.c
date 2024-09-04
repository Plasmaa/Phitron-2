#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d", &T);

    while(T--)
    {
        int n;
        scanf("%d", &n);

        int a[n], b[n], c[n];

        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }

        int temp;
        for (int i=0; i<n-1; i++)
        {
            for (int j=0; j<n-i-1; j++)
            {
                if (b[j] > b[j+1])
                {
                    temp=b[j];
                    b[j]=b[j+1];
                    b[j+1]=temp;
                }
            }
        }


        for(int i=0; i<n; i++)
        {
            if (a[i]>b[i])
            {
                c[i]=a[i]-b[i];
            }
            else
            {
                c[i]=b[i]-a[i];
            }
        }


        for(int i=0; i<n; i++)
        {
            printf("%d ", c[i]);
        }
        printf("\n");
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

