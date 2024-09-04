#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    cin.ignore();

    while (T--)
    {
        string s, x, temp;
        getline(cin, temp);
        stringstream ss(temp);
        ss >> s >> x;

        string result;
        int len1 = s.size();
        int len2 = x.size();

        for (int i = 0; i < len1; i++)
        {
            if (i <= len1 && s.find(x, i) == i)
            {
                result += '#';
                i += len2 - 1;
            }
            else
            {
                result += s[i];
            }
        }
        cout << result << endl;
    }

    return 0;
}
