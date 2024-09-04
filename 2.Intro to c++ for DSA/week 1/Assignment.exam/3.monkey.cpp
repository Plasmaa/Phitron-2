#include <bits/stdc++.h>

using namespace std;

int main()
{
    char a[100005];

    while (cin.getline(a, 100005))
    {
        int n = strlen(a);

        sort(a, a + n);

        for (int i = 0; i < n; i++)
        {
            if (a[i] != ' ')
            {
                cout << a[i];
            }
        }

        cout << "\n";
    }

    return 0;
}
