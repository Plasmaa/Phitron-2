/*

BFS, dijkstra , bellman -> (all are single souce shortest path). To find the distance of a node we have to declare a root
or source node , so the time complexity will be :
For BFS : O (V+E)*V = v^3 (E^2 = V)
For Dijkstra : O [{(V+E)*logv}*V] = v^3log(v)
For Bellman Ford : O (V*E)*V = V^4
this complexity is way too more, so we use floyd because :

floyd -> All pair shortest path :
time complexity of floyd : O (v^3).
floyd can do everything :
a) shortest distance (of BFS)
b) negative cycle (of Bellman ford)
c) distance in weighted graph (of Dijkstra)

so its a all in one package , with the time complexity of only O(v^3) !

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
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }

    // time complexity -> O(V*E)
    dis[0] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (Edge ed : EdgeList)
        {
            int u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;
            if (dis[u] < INT_MAX && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }
    bool cycle = false;
    for (Edge ed : EdgeList)
    {
        int u, v, c;
        u = ed.u;
        v = ed.v;
        c = ed.c;
        if (dis[u] < INT_MAX && dis[u] + c < dis[v])
        {
            cycle = true;
            break;
        }
    }
    if (cycle)
    {
        cout << "Cycle found. No answer" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
            cout << i << " -> " << dis[i] << endl;
    }
    return 0;
}