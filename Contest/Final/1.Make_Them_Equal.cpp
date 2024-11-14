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
        int n, k;
        cin >> n >> k;

        string a, b;
        cin >> a >> b;

        int diff = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                diff++;
            }
        }
        if (diff <= k)
        {
            yes;
        }
        else
        {
            no;
        }
    }

    return 0;
}
