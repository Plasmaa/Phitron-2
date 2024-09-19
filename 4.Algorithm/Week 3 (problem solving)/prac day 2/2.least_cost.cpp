/*
problem link: https://tinyurl.com/5rx6rdaa
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int par[500000];
    int group_size[500000];

    void dsu_init(int V)
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
        return par[node] = find(par[node]);
    }

    void dsu_union_size(int node1, int node2)
    {
        int leader1 = find(node1);
        int leader2 = find(node2);

        if (leader1 != leader2)
        {
            if (group_size[leader1] > group_size[leader2])
            {
                par[leader2] = leader1;
                group_size[leader1] += group_size[leader2];
            }
            else
            {
                par[leader1] = leader2;
                group_size[leader2] += group_size[leader1];
            }
        }
    }

    int spanningTree(int V, vector<vector<int>> adj[])
    {
        dsu_init(V);

        vector<tuple<int, int, int>> edges;

        for (int u = 0; u < V; u++)
        {
            for (auto it : adj[u])
            {
                int v = it[0];
                int w = it[1];
                if (u < v)
                {
                    edges.push_back(make_tuple(w, u, v));
                }
            }
        }

        sort(edges.begin(), edges.end());

        int mst_weight = 0;
        int edge_count = 0;

        for (auto &edge : edges)
        {
            int w = get<0>(edge);
            int u = get<1>(edge);
            int v = get<2>(edge);

            if (find(u) != find(v))
            {
                dsu_union_size(u, v); // Union the sets of u and v
                mst_weight += w;      // Add weight of the edge to the MST
                edge_count++;
                if (edge_count == V - 1) // MST will have exactly V-1 edges
                    break;
            }
        }

        return mst_weight;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends