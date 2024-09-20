#include <bits/stdc++.h>
using namespace std;

bool is_vowel(char ch)
{
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    {
        return true;
    }
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        string s;
        cin >> s;

        int v = 0, c = 0, d = 0;

        for (char ch : s)
        {
            if (ch < 97)
            {
                d++;
            }
            else if (is_vowel(ch))
            {
                v++;
            }
            else
            {
                c++;
            }
        }

        int total = 0;

        while (v > 0 || c > 0 || d > 0)
        {
            int c_box = min(3, c);
            int v_box = min(2, v);
            int d_box = min(1, d);

            c -= c_box;
            v -= v_box;
            d -= d_box;

            total++;
        }

        cout << total << endl;
    }

    return 0;
}
