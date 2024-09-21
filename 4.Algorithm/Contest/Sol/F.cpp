#include <bits/stdc++.h>
#define no cout << "NO" << '\n'
#define yes cout << "YES" << '\n'
#define all(x) x.begin(), x.end()
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<vector<int64_t>> dp(n + 1, vector<int64_t>(26, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i + 1][str[i] - 'a']++;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            dp[i][j] += dp[i - 1][j];
        }
    }

    int q;
    cin >> q;

    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        int cnt = 0;

        for (int i = 0; i < 26; i++)
        {
            if ((dp[r][i] - dp[l - 1][i]) % 2 == 1)
            {
                cnt++;
            }
        }

        if (cnt / 2 <= k)
        {
            yes;
        }
        else
            no;
    }
}

int main()
{
    fast();
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}