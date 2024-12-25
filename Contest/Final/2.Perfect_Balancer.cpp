#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int total_sum = 0;
    for (int i = 0; i < n; i++)
    {
        total_sum += a[i];
    }

    int half_sum = total_sum / 2;

    int current_sum = 0;
    for (int i = 0; i < n; i++)
    {
        current_sum += a[i];

        if (current_sum == half_sum)
        {
            cout << (i + 1) << " " << a[i] << endl;
            return 0;
        }
    }

    cout << "UNSTABLE" << endl;
    return 0;
}
