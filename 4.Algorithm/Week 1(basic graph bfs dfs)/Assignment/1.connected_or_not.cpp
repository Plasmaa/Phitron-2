#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e;
    cin >> n >> e;
    vector<int> mat[n];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
    }
    vector<int> v;

    int q;
    cin >> q;

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        bool f = false;

        for (auto it : mat[a])
        {
            if (it == b)
                f = true;
        }
        if (f == true || a == b)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}