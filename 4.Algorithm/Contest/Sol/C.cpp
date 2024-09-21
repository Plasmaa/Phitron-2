#include <bits/stdc++.h>
#define no cout << "NO" << '\n'
#define yes cout << "YES" << '\n'
#define all(x) x.begin(), x.end()
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int64_t f(int64_t i)
{
    if (i < 3)
        return 0;
    return i / 3 + f((i % 3) + i / 3);
}

void solve()
{
    int64_t n;
    cin >> n;
    cout << (n / 5) + f(n / 5) << endl;
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