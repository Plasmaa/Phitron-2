#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e;
    cin >> n >> e;
    int mat[n][n];
    memset(mat, 0, sizeof(mat)); // this automatically sets the value of every position as 0.

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        mat[a][b] = 1;
        mat[b][a] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    if (mat[0][1] == 1)
        cout << "connection" << endl;
    else
        cout << "No connection" << endl;

    return 0;
}