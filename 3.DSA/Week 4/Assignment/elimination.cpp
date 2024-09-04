#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        stack<char> st;

        for (char ch : S)
        {
            if (!st.empty() && st.top() == '0' && ch == '1')
            {
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }

        if (st.empty())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
