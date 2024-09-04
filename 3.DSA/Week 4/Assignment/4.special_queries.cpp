#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    queue<string> q;
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        int f;
        cin >> f;

        if (f == 0)
        {
            string name;
            cin >> name;
            q.push(name);
        }
        else if (f == 1)
        {
            if (!q.empty())
            {
                cout << q.front() << endl;
                q.pop();
            }
            else
            {
                cout << "Invalid" << endl;
            }
        }
    }

    return 0;
}
