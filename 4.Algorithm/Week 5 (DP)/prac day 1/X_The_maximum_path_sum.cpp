#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long int ll;
using namespace std;

const int INF = -1e9;
int dp[11][11];
int N, M;

int max_sum(vector<vector<int>> &mat, int n, int m)
{
    if (n > N || m > M)
        return INF;

    if (n == N && m == M)
        return mat[n][m];

    if (dp[n][m] != -1)
        return dp[n][m];

    int right = max_sum(mat, n, m + 1);
    int down = max_sum(mat, n + 1, m);

    return dp[n][m] = mat[n][m] + max(right, down);
}

int main()
{
    fast();

    cin >> N >> M;

    vector<vector<int>> mat(N + 1, vector<int>(M + 1));
    memset(dp, -1, sizeof(dp));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> mat[i][j];
        }
    }

    cout << max_sum(mat, 1, 1) << endl;

    return 0;
}
