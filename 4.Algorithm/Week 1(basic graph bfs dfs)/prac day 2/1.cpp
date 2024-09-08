#include <bits/stdc++.h>

using namespace std;

vector<int> adj_list[1000];
bool visited[1000];
int node = 0;

void DFS(int src)
{
    visited[src] = true;
    node++;

    for (auto it : adj_list[src])
    {
        if (visited[it] == false)
        {
            DFS(it);
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
    // memset(visited, false, sizeof(visited));

    int src;
    cin >> src;

    DFS(src);
    cout << node << endl;

    return 0;
}