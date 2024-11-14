#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ll n, q;
    cin >> n >> q;

    // Initialize DP array
    vector<ll> dp(n + 1, 0); // DP array to store cumulative sums

    // Fill the dp array based on the given sequence structure
    for (ll i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1] + ((i + 1) / 2); // Sum of first 'i' elements
    }

    // Process each query
    while (q--)
    {
        ll l, r;
        cin >> l >> r;

        // Calculate the sum from index l to r using the dp table
        ll sum = dp[r] - dp[l - 1]; // Subtract the prefix sum up to l-1

        cout << sum << endl;
    }

    return 0;
}
