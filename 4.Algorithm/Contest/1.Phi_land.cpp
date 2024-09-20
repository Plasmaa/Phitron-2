#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    string s;

    getline(cin, s);
    s[0] = tolower(s[0]);
    reverse(s.begin(), s.end());
    cout << s << "\n";

    return 0;
}
