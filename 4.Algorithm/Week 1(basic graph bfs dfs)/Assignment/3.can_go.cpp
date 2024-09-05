#include <bits/stdc++.h>
using namespace std;

int n, m;
bool vis[1005][1005];
char a[1005][1005];

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    if (a[i][j] == '#' || vis[i][j])
        return false;
    return true;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        int x = par.first, y = par.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ni = x + d[i].first;
            int nj = y + d[i].second;
            if (valid(ni, nj))
            {
                q.push({ni, nj});
                vis[ni][nj] = true;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    pair<int, int> start, end;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'A')
                start = {i, j};
            if (a[i][j] == 'B')
                end = {i, j};
        }
    }

    memset(vis, false, sizeof(vis));

    bfs(start.first, start.second);

    if (vis[end.first][end.second])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
