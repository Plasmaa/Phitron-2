#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
vector<pair<int, int>> adj[N];
long long int dis[N];

class cmp
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

void dijkstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({src, 0});
    dis[src] = 0;

    while (!pq.empty())
    {
        int node = pq.top().first;
        long long int cost = pq.top().second;
        pq.pop();

        for (auto it : adj[node])
        {
            int child = it.first;
            long long int child_cost = it.second;

            if (cost + child_cost < dis[child])
            {
                dis[child] = cost + child_cost;
                pq.push({child, dis[child]});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e;
    cin >> n >> e;

    for (int i = 1; i <= e; i++)
    {
        int a, b;
        long long int w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }

    int s;
    cin >> s;

    for (int i = 0; i <= N; i++)
    {
        dis[i] = INT_MAX;
    }

    dijkstra(s);

    int t;
    cin >> t;

    while (t--)
    {
        int d;
        long long int dw;
        cin >> d >> dw;

        if (dis[d] <= dw)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
