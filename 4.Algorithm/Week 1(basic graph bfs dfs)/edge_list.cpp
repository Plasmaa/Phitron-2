#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e;
    cin >> n >> e;

    vector<pair<int, int>> p;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        // p.push_back({a,b});
        p.push_back(make_pair(a, b));
    }

    // for (auto it : p)
    // {
    //     cout << it.first << " " << it.second << endl;
    // }
    for (pair<int, int> it : p)
    {
        cout << it.first << " " << it.second << endl;
    }

    return 0;
}