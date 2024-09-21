#include <bits/stdc++.h>
#define no cout << "NO" << '\n'
#define yes cout << "YES" << '\n'
#define all(x) x.begin(), x.end()
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

bool isV(char ch)
{
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

void solve()
{
    string str;
    cin >> str;
    int v = 0, c = 0, d = 0;
    for (char ch : str)
    {
        if (isV(ch))
            v++;
        else if (ch >= '0' and ch <= '9')
            d++;
        else
            c++;
    }
    int ans = 0;
    while (c > 0 or v > 0 or d > 0)
    {
        d--;
        c -= min(3, c);
        v -= min(v, 2);
        ans++;
    }
    cout << ans << endl;
}
int main()
{
    fast();
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}