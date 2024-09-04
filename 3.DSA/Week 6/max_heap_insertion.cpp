#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);

        int idx = v.size() - 1;
        while (idx != 0)
        {
            int parent_idx = (idx - 1) / 2;
            if (v[parent_idx] < v[idx])
                swap(v[parent_idx], v[idx]);
            idx = parent_idx;
        }
    }

    for (int val : v)
        cout << val << " ";

    return 0;
}
