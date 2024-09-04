#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        stack<char> st;

        for (char ch : s)
        {
            if (ch == '1' && !st.empty() && st.top() == '0')
            {
                st.pop();
            }
            else if (ch == '0' && !st.empty() && st.top() == '1')
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
