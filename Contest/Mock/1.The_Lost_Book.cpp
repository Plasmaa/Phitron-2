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

    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int z;
    cin >> z;

    bool f = false;
    int gg;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == z)
        {
            f = true;
            gg = i;
            break;
        }
    }

    if (f)
        cout << gg << endl;

    else
        cout << -1 << endl;

    return 0;
}