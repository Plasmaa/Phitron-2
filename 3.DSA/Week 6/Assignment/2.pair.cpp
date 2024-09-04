#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int> &a, pair<string, int> &b)
{
    if (a.first != b.first)
        return a.first < b.first;
    return a.second > b.second;
}

int main()
{
    int n;
    cin >> n;

    vector<pair<string, int>> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end(), cmp);

    for (auto it : a)
    {
        cout << it.first << " " << it.second << endl;
    }

    return 0;
}
