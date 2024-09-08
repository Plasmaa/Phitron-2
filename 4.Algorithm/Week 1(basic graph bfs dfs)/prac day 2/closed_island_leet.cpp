#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int N = 1e5 + 5;
    bool visited[100][100];
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

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

        memset(visited, false, sizeof(visited));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (!visited[i][j] && grid[i][j] == 0)
                {
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>>() grid;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            grid[i][j].push_back(x);
        }
    }

    Solution s;
    cout << s.closedIsland(grid) << "\n"; // Pass the grid as vector

    return 0;
}
