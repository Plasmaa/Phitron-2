#include <bits/stdc++.h>
using namespace std;

char building[1005][1005];
bool vis[1005][1005];

int n, m;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool valid(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m && building[x][y] == '.' && !vis[x][y])
    {
        return true;
    }
    return false;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty())
    {
        pair<int, int> node = q.front();
        q.pop();
        int nrow = node.first;
        int ncol = node.second;

        for (int i = 0; i < 4; i++)
        {
            int ci = nrow + dx[i];
            int cj = ncol + dy[i];

            if (valid(ci, cj))
            {
                vis[ci][cj] = true;
                q.push({ci, cj});
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> building[i][j];
        }
    }

    int appartment = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (building[i][j] == '.' && !vis[i][j])
            {
                bfs(i, j);
                appartment++;
            }
        }
    }
    cout << appartment << endl;

    return 0;
}
