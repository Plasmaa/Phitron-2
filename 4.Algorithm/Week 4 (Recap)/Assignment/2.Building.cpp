#include <bits/stdc++.h>
using namespace std;
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const long long int N = 1e9 + 5;
long long parent[N];
long long group_size[N];

void dsu_initialize(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
    }
}

int dsu_find(int node)
{
    if (parent[node] == -1)
        return node;
    return parent[node] = dsu_find(parent[node]);
}

void dsu_union_by_size(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    if (leaderA != leaderB)
    {
        if (group_size[leaderA] > group_size[leaderB])
        {
            parent[leaderB] = leaderA;
            group_size[leaderA] += group_size[leaderB];
        }
        else
        {
            parent[leaderA] = leaderB;
            group_size[leaderB] += group_size[leaderA];
        }
    }
}

class Edge
{
public:
    long long u, v, w;
    Edge(long long u, long long v, long long w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int main()
{
    fast();

    long long n, e;
    cin >> n >> e;

    dsu_initialize(n);

    vector<Edge> edgeList;

    while (e--)
    {
        long long u, v, w;
        cin >> u >> v >> w;
        edgeList.push_back(Edge(u, v, w));
    }

    sort(edgeList.begin(), edgeList.end(), cmp);

    long long total_Cost = 0;
    long long edges_Used = 0;

    for (Edge ed : edgeList)
    {
        long long leaderU = dsu_find(ed.u);
        long long leaderV = dsu_find(ed.v);

        if (leaderU != leaderV)
        {
            dsu_union_by_size(ed.u, ed.v);
            total_Cost += ed.w;
            edges_Used++;
        }
    }

    if (edges_Used == n - 1)
    {
        cout << total_Cost << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}
