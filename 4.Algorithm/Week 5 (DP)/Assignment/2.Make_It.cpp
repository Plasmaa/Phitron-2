#include <bits/stdc++.h>
#define no cout << "NO" << '\n'
#define yes cout << "YES" << '\n'
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long int ll;
using namespace std;

int dp[100005];

bool can_reach(int n, int target)
{
    if (n > target)
        return false;
    if (n == target)
        return true;

    if (dp[n] != -1)
        return dp[n];

    bool op1 = can_reach(n + 3, target);
    bool op2 = can_reach(n * 2, target);

    // Store the result in dp array
    return dp[n] = op1 || op2;
}

int main()
{
    fast();
    int t;
    cin >> t;

    while (t--)
    {
        int input;
        cin >> input;

        memset(dp, -1, sizeof(dp));

        if (can_reach(1, input))
            yes;
        else
            no;
    }

    return 0;
}
