/*
    https://leetcode.com/problems/find-if-path-exists-in-graph/description/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> v[200005];
    bool vis[200005];
    void dfs(int s)
    {
        vis[s] = true;
        for (int child : v[s])
        {
            if (!vis[child])
            {
                dfs(child);
            }
        }
    }
    bool validPath(int n, vector<vector<int>> &edges, int source, int d)
    {
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < edges.size(); i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(source);
        return vis[d];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> edges;

    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    Solution s;

    bool gg = s.validPath(1, edges, 0, 5);
    cout << gg;

    return 0;
}