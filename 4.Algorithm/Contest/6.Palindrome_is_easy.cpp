#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    int n;
    cin >> n;

    string s;

    for (int i = 0; i < n; i++)
    {
        char a;
        cin >> a;
        s += a;
    }

    int q;
    cin >> q;

    while (q--)
    {
        int l, r, op;
        cin >> l >> r >> op;

        l--;
        r--;

        int freq[26];
        memset(freq, 0, sizeof(freq));

        for (int i = l; i <= r; i++)
        {
            freq[s[i] - 'a']++;
        }

        int odd_count = 0;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] % 2 != 0)
                odd_count++;
        }

        if (odd_count / 2 <= op)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}
