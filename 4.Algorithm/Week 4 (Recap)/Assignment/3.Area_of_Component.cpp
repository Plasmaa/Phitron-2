#include <bits/stdc++.h>
using namespace std;

class gg
{
public:
    bool vis[1005][1005];
    int ans, n, m;
    vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    bool valid(int ci, int cj)
    {
        return (ci >= 0 && ci < n && cj >= 0 && cj < m);
    }

    void dfs(int si, int sj, vector<vector<char>> &grid)
    {
        vis[si][sj] = true;
        ans++;
        for (int i = 0; i < 4; i++)
        {
            int ci = si + d[i].first;
            int cj = sj + d[i].second;
            if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
            {
                dfs(ci, cj, grid);
            }
        }
    }

    int min_area(vector<vector<char>> &grid)
    {
        memset(vis, false, sizeof(vis));
        n = grid.size();
        m = grid[0].size();
        int min_area = INT_MAX;
        bool found_component = false;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == '.')
                {
                    ans = 0;
                    found_component = true;
                    dfs(i, j, grid);
                    min_area = min(min_area, ans);
                }
            }
        }

        if (!found_component)
        {
            return -1;
        }

        return min_area;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    gg a;
    cout << a.min_area(grid) << endl;

    return 0;
}
