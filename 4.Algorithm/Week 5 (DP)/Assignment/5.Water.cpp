#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
    fast();

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        int max1 = -1;
        int max2 = -1;

        // First pass to find max1
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (max1 < a[i])
                max1 = a[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (a[i] > max2 && a[i] < max1)
            {
                max2 = a[i];
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (a[i] == max1 || a[i] == max2)
            {
                cout << i << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
