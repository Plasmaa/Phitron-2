#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    stringstream ss(s);
    string word;
    int f = 0;

    while (ss >> word)
    {
        if (word == "Jessica")
        {
            f = 1;
            break;
        }
    }

    if (f==1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
