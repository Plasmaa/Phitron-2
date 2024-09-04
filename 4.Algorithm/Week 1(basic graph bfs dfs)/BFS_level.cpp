#include <bits/stdc++.h>

using namespace std;

bool visited[1003];
vector<int> adj_list[1003];
int level[1003];

void bfs(int root)
{
    queue<int> q;
    q.push(root);
    visited[root] = true;
    level[root] = 0;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        for (auto child : adj_list[parent])
        {
            if (!visited[child])
            {
                q.push(child);
                visited[child] = true;
                level[child] = level[parent] + 1;
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
    memset(level, -1, sizeof(level));
    bfs(root);

    for (int i = 0; i < n; i++)
    {
        cout << "value : " << i << ", level : " << level[i] << endl;
    }

    return 0;
}