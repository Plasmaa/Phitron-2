/*
    https://leetcode.com/problems/number-of-closed-islands/description/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n, m;
    bool vis[105][105];
    vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    bool valid(int ci, int cj)
    {
        if (ci >= 0 && ci < n && cj >= 0 && cj < m)
            return true;
        else
            return false;
    }
    bool flag;
    void dfs(int si, int sj, vector<vector<int>> &grid)
    {
        vis[si][sj] = true;
        if (si == 0 || si == n - 1 || sj == 0 || sj == m - 1)
            flag = false;
        for (int i = 0; i < 4; i++)
        {
            int ci = si + d[i].first;
            int cj = sj + d[i].second;
            if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == 0)
            {
                dfs(ci, cj, grid);
            }
        }
    }
    int closedIsland(vector<vector<int>> &grid)
    {
        memset(vis, false, sizeof(vis));
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == 0)
                {
                    flag = true;
                    dfs(i, j, grid);
                    if (flag == true)
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};

class Solution
{
public:
    int N = 1e5 + 5;
    bool visited[100]
                [100]; // Assuming the grid size is <= 100 as per constraints
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    // BFS to explore the island
    bool bfs(int i, int j, vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;
        bool isClosed = true;

        while (!q.empty())
        {
            pair<int, int> node = q.front();
            q.pop();
            int x = node.first, y = node.second;

            // Check all four directions
            for (int k = 0; k < 4; k++)
            {
                int newX = x + dx[k];
                int newY = y + dy[k];

                // If we are on the edge, it's not a closed island
                if (newX < 0 || newY < 0 || newX >= grid.size() ||
                    newY >= grid[0].size())
                {
                    isClosed = false;
                }
                else if (!visited[newX][newY] && grid[newX][newY] == 0)
                {
                    q.push({newX, newY});
                    visited[newX][newY] = true;
                }
            }
        }

        return isClosed;
    }

    int closedIsland(vector<vector<int>> &grid)
    {
        int closedIslands = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        // Initialize visited array
        memset(visited, false, sizeof(visited));

        // Traverse the grid
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (!visited[i][j] && grid[i][j] == 0)
                {
                    // If BFS returns true, it means the island is closed
                    if (bfs(i, j, grid))
                    {
                        closedIslands++;
                    }
                }
            }
        }

        return closedIslands;
    }
};

* /
