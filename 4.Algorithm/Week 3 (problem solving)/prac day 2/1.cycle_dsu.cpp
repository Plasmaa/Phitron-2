/*
problem link : https://tinyurl.com/ycxyhpn2

logic : to find if the dsu has a cycle or not we have to check if two node of the dsu shares same parent

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int par[100000];
    int group_size[100000];

    void dsu_init(int V, vector<int> adj[])
    {
        for (int i = 0; i < V; i++)
        {
            par[i] = -1;
            group_size[i] = 1;
        }
    }

    int find(int node)
    {
        if (par[node] == -1)
            return node;
        else
        {
            int leader = find(par[node]);
            par[node] = leader;
            return leader;
        }
    }

    void dsu_union_size(int node1, int node2)
    {
        int leaderA = find(node1);
        int leaderB = find(node2);

        if (group_size[leaderA] > group_size[leaderB])
        {
            par[leaderB] = leaderA;
            group_size[leaderA] += group_size[leaderB];
        }
        else
        {
            par[leaderA] = leaderB;
            group_size[leaderB] += group_size[leaderA];
        }
    }

    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        dsu_init(V, adj);

        // Traverse all edges of the graph
        for (int u = 0; u < V; u++)
        {
            for (int v : adj[u])
            {
                if (u < v)
                {
                    int leaderU = find(u);
                    int leaderV = find(v);

                    if (leaderU == leaderV)
                    { // If both nodes have the same leader, there's a cycle
                        return true;
                    }

                    dsu_union_size(u, v); // Otherwise, union the two sets
                }
            }
        }
        return false; // No cycle found
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}