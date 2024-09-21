#include <bits/stdc++.h>
#define no cout << "NO" << '\n'
#define yes cout << "YES" << '\n'
#define all(x) x.begin(), x.end()
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
void solve()
{
    string str;
    cin >> str;
    for (auto &it : str)
    {
        it = towlower(it);
    }
    cout << string(str.rbegin(), str.rend()) << endl;
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