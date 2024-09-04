#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();

    while (t--)
    {
        string s;
        getline(cin, s);

        map<string, int> mp;
        stringstream ss(s);
        string word;

        string x;
        int count = 0;

        while (ss >> x)
        {
            mp[x]++;

            if (mp[x] > count)
            {
                word = x;
                count = mp[x];
            }
        }

        cout << word << " " << count << endl;
    }

    return 0;
}
