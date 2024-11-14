#include <bits/stdc++.h>
#define no cout << "NO" << '\n'
#define yes cout << "YES" << '\n'
#define all(x) x.begin(), x.end()
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long int ll;
using namespace std;

int main()
{
    fast();

    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        vector<ll> a(n - 2);
        ll a_sum = 0;

        for (int i = 0; i < n - 2; i++)
        {
            cin >> a[i];
            a_sum += a[i];
        }

        ll sum;
        cin >> sum;

        ll target_sum = sum - a_sum;

        cout << target_sum + 1 << endl;
    }

    return 0;
}
