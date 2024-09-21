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
    vector<int64_t> vec(n), pre = {0};
    for (auto &it : vec)
    {
        cin >> it;
        pre.push_back(it + pre.back());
    }
    int q;
    cin >> q;
    while (q--)
    {
        int64_t sum;
        cin >> sum;
        auto it = lower_bound(all(pre), sum);
        if (it != pre.end())
        {
            cout << it - pre.begin() << '\n';
        }
        else
            cout << -1 << "\n";
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