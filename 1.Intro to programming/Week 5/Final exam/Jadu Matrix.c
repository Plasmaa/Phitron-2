#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int n, m;
    scanf("%d %d", &n, &m);

    if (n != m)
    {
        printf("NO\n");
        return 0;
    }

    int matrix[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int f = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i == j || i + j == N - 1))
            {
                if (matrix[i][j] != 1)
                {
                    f = 0;
                    break;
                }
            }
            else
            {
                if (matrix[i][j] != 0)
                {
                    f = 0;
                    break;
                }
            }
        }
        if (f==1)
        {
            break;
        }
    }

    if (f)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

