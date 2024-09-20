#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    int n;
    cin >> n;
    long long int a[n + 1];

    a[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    int q;
    cin >> q;

    while (q--)
    {
        long long int z;
        cin >> z;

        int f = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] >= z)
            {
                cout << i << "\n";
                f = 1;
                break;
            }
        }

        if (f == 0)
        {
            cout << -1 << "\n";
        }
    }

    return 0;
}
