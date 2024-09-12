#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
long long int dis[N];

class Edge
{
public:
    int u, v;
    long long w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e;
    cin >> n >> e;

    vector<Edge> edgeList;

    for (int i = 0; i < e; i++)
    {
        int u, v;
        long long int w;
        cin >> u >> v >> w;
        edgeList.push_back(Edge(u, v, w));
    }

    int s;
    cin >> s;

    for (int i = 1; i <= n; i++)
    {
        dis[i] = LLONG_MAX;
    }
    dis[s] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (auto it : edgeList)
        {
            int u, v;
            long long w;
            u = it.u;
            v = it.v;
            w = it.w;
            if (dis[u] < LLONG_MAX && dis[u] + w < dis[v])
            {
                dis[it.v] = dis[it.u] + it.w;
            }
        }
    }

    bool cycle = false;
    for (auto it : edgeList)
    {
        int u, v;
        long long w;
        u = it.u;
        v = it.v;
        w = it.w;
        if (dis[u] < LLONG_MAX && dis[u] + w < dis[v])
        {
            cycle = true;
            break;
        }
    }

    if (cycle)
    {
        cout << "Negative Cycle Detected" << endl;
    }
    else
    {
        int t;
        cin >> t;

        while (t--)
        {
            int d;
            cin >> d;

            if (dis[d] == LLONG_MAX)
            {
                cout << "Not Possible" << endl;
            }
            else
            {
                cout << dis[d] << endl;
            }
        }
    }

    return 0;
}
