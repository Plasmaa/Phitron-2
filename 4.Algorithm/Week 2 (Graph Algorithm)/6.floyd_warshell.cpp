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
#define ll long long int
using namespace std;

int main()
{
    ll n, e;
    cin >> n >> e;
    ll adj[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adj[i][j] = INT_MAX;
            if (i == j)
                adj[i][j] = 0;
        }
    }
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = c;
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj[i][k] + adj[k][j] < adj[i][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }
    // cout << "AFTER" << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (adj[i][j] == INT_MAX)
    //             cout << "INF ";
    //         else
    //             cout << adj[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < n; i++)
    {
        if (adj[i][i] < 0)
        {
            cout << "Cycle detected" << endl;
            break;
        }
    }
    return 0;
}