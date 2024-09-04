#include <bits/stdc++.h>

using namespace std;

bool visited[1003];
vector<int> adj_list[1003];

void bfs(int root)
{
    queue<int> q;
    q.push(root);
    visited[root] = true;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        cout << parent << endl;

        for (auto child : adj_list[parent])
        {
            if (!visited[child])
            {
                q.push(child);
                visited[child] = true;
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

    int root;
    cin >> root;
    memset(visited, false, sizeof(visited));
    bfs(root);

    return 0;
}