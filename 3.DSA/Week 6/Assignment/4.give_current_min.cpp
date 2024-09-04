#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        pq.push(val);
    }

    int q;
    cin >> q;

    while (q--)
    {
        int c;
        cin >> c;

        if (c == 0)
        {
            int x;
            cin >> x;
            pq.push(x);
            cout << pq.top() << endl;
        }
        else if (c == 1)
        {
            if (pq.empty())
            {
                cout << "Empty" << endl;
            }
            else
            {
                cout << pq.top() << endl;
            }
        }
        else if (c == 2)
        {
            if (pq.empty())
            {
                cout << "Empty" << endl;
            }
            else
            {
                pq.pop();
                if (pq.empty())
                {
                    cout << "Empty" << endl;
                }
                else
                {
                    cout << pq.top() << endl;
                }
            }
        }
    }

    return 0;
}
