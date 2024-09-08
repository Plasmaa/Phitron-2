#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 1;
bool visited[N];
vector<int> adj_list[N];

void BFS(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
        int head = q.front();
        q.pop();

        for (auto it : adj_list[head])
        {
            if (visited[it] == false)
            {
                visited[it] = true;
                q.push(it);
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

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    int component = 0;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            BFS(i);
            component++;
        }
    }

    cout << component << endl;

    return 0;
}