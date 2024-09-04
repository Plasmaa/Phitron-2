#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N, S;
        cin >> N >> S;
        int A[N];
        for (int i = 0; i < N; ++i)
        {
            cin >> A[i];
        }

        int f = 0;
        for (int i = 0; i < N  ; ++i)
        {
            for (int j = i + 1; j < N  ; ++j)
            {
                for (int k = j + 1; k < N  ; ++k)
                {
                    if (A[i] + A[j] + A[k] == S)
                    {
                        f = 1;
                        break;
                    }
                }
            }
        }

        if (f)
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
