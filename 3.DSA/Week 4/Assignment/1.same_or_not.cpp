#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    stack<int> st;
    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    int f = 1;

    if (n != m)
    {
        f = 0;
    }
    else
    {
        while (!st.empty() && !q.empty())
        {
            if (st.top() != q.front())
            {
                f = 0;
                break;
            }
            st.pop();
            q.pop();
        }
    }

    if (f == 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
