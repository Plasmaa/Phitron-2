#include <bits/stdc++.h>
#define no cout << "Impossible" << '\n'
#define yes cout << "Possible" << '\n'
#define all(x) x.begin(), x.end()
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long int ll;
using namespace std;

int main()
{
    fast();

    string word1, word2;

    while (cin >> word1 >> word2)
    {
        int len1 = word1.size();
        int len2 = word2.size();

        int i = 0, j = 0;

        while (i < len1 && j < len2)
        {
            if (word1[i] == word2[j])
            {
                j++;
            }
            i++;
        }

        if (j == len2)
        {
            yes;
        }
        else
        {
            no;
        }
    }

    return 0;
}
