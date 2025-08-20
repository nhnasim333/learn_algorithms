#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
int parent[1005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    parent[src] = -2;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int child : adj_list[par])
        {
            if (parent[child] == -1)
            {
                q.push(child);
                parent[child] = par;
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(parent, -1, sizeof(parent));
    int src, dst;
    cin >> src >> dst;
    bfs(src);

    if (parent[dst] == -1)
    {
        cout << "No path exists from " << src << " to " << dst << endl;
        return 0;
    }

    vector<int> path;
    int node = dst;
    while (node != -2)
    {
        path.push_back(node);
        node = parent[node];
    }

    reverse(path.begin(), path.end());
    for (int x : path)
        cout << x << " ";

    return 0;
}