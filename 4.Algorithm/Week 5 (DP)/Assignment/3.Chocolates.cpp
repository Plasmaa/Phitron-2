#include <bits/stdc++.h>
#define no cout << "NO" << '\n'
#define yes cout << "YES" << '\n'
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
    fast();

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int a[n], s = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            s += a[i];
        }

        if (s % 2 != 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            int sum = s / 2;
            bool dp[n + 1][sum + 1];

            dp[0][0] = true;
            for (int i = 1; i <= sum; i++)
                dp[0][i] = false;

            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j <= sum; j++)
                {
                    if (a[i - 1] <= j)
                    {
                        dp[i][j] = dp[i - 1][j - a[i - 1]] || dp[i - 1][j];
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
            if (dp[n][sum])
                yes;
            else
                no;
        }
    }

    return 0;
}
