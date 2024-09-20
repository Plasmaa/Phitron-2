#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    int T;
    cin >> T;
    int chocolate;
    int more_chocolate;
    while (T--)
    {
        int tk;
        cin >> tk;

        chocolate = tk / 5;
        more_chocolate = chocolate;

        while (more_chocolate >= 3)
        {
            int new_chocolates = more_chocolate / 3;
            chocolate += new_chocolates;
            more_chocolate = new_chocolates + (more_chocolate % 3);
        }
        cout << chocolate << endl;
    }

    return 0;
}