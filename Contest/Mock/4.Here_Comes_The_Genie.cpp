#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int max_balls = 0;
    int prev = INT_MAX;

    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] < prev)
        {
            max_balls += a[i];
            prev = a[i];
        }
        else
        {
            if (prev > 0)
            {
                max_balls += prev - 1;
                prev--;
            }
        }
    }

    cout << max_balls << endl;

    return 0;
}
