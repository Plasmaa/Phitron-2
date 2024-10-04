#include <bits/stdc++.h>
#define no cout << "NO" << '\n'
#define yes cout << "YES" << '\n'
#define all(x) x.begin(), x.end()
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long int ll;
using namespace std;

const int MAX_N = 10001;
int dp[MAX_N];

int max_coin(vector<int> &a, int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return a[0];

    if (dp[n] != -1)
        return dp[n];

    ll op1 = max_coin(a, n - 1);
    ll op2 = max_coin(a, n - 2) + a[n];
    return dp[n] = max(op1, op2);

    return dp[n];
}

int main()
{
    fast();

    int t;
    cin >> t;
    int i = 1;

    while (t--)
    {
        memset(dp, -1, sizeof(dp));
        int n;
        cin >> n;

        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            int z;
            cin >> z;
            a.push_back(z);
        }
        int mx = max_coin(a, n - 1);

        cout << "Case " << i << ": " << mx << "\n";
        i++;
    }

    return 0;
}

/*

#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
    fast();
    int t;
    cin >> t;
    int case_num = 1;

    while (t--)
    {
        int n;
        cin >> n;

        vector<long long> a(n); // Monster coins
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        if (n == 0)
        {
            cout << "Case " << case_num++ << ": 0\n";
            continue;
        }

        // DP array to store the maximum coins up to each monster
        vector<long long> dp(n, 0);
        dp[0] = a[0];
        if (n > 1)
        {
            dp[1] = max(a[0], a[1]);
        }

        for (int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
        }

        // The result is the maximum coins we can collect up to the last monster
        cout << "Case " << case_num++ << ": " << dp[n - 1] << "\n";
    }

    return 0;
}
*/