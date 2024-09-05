#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
vector<int> v[N];

int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int q;
    cin >> q;

    while (q--)
    {
        int x;
        cin >> x;

        if (v[x].size() == 0)
        {
            cout << "-1" << endl;
        }
        else
        {
            sort(v[x].rbegin(), v[x].rend());

            for (int node : v[x])
            {
                cout << node << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
