/*

problem - https://basecamp.eolymp.com/en/problems/1453

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int dis[N];

class Edge
{
public:
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> EdgeList;
    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u, v, c));
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = 100;
    }

    // time complexity -> O(V*E)
    dis[1] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (Edge ed : EdgeList)
        {
            int u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;
            if (dis[u] < 100 && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] == 100)
        {
            cout << 3000 << " ";
        }
        else
        {
            cout << dis[i] << " ";
        }
    }

    return 0;
}