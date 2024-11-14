#include <bits/stdc++.h>
using namespace std;

int dp[100][100];

bool can_even(int a[], int n, int s)
{
    if (n == 0)
    {
        return s == 0;
    }
    if (dp[n][s] != -1)
        return dp[n][s];
    if (a[n - 1] <= s)
    {
        bool op1 = can_even(a, n - 1, s - a[n - 1]);
        bool op2 = can_even(a, n - 1, s);
        return dp[n][s] = op1 || op2;
    }
    else
    {
        return dp[n][s] = can_even(a, n - 1, s);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int max_even = -1;

    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            max_even = max(max_even, a[i]);
        }
    }

    int max_even_sum = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = a[i] + a[j];
            if (sum % 2 == 0)
            {
                max_even_sum = max(max_even_sum, sum);
            }
        }
    }

    cout << max(max_even, max_even_sum) << '\n';

    return 0;
}
