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
    int64_t sz = (int64_t)pow(2, n);
    sz--;
    vector<int64_t> vec(sz);
    for (auto &it : vec)
    {
        cin >> it;
    }
    queue<pair<int64_t, int64_t>> q;
    q.push({0, sz - 1});
    while (!q.empty())
    {
        auto pr = q.front();
        int64_t l = pr.first, r = pr.second;
        int64_t mid = (l + r) / 2;
        cout << vec[mid] << " ";
        if (l < mid)
            q.push({l, mid - 1});
        if (mid < r)
            q.push({mid + 1, r});
        q.pop();
    }
    cout << endl;
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