#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool vis[1005];
int parent[1005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    parent[src] = -1;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int child : adj_list[par])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
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

    int q;
    cin >> q;
    while (q--)
    {
        int src, dst;
        cin >> src >> dst;

        memset(vis, false, sizeof(vis));
        memset(parent, -1, sizeof(parent));

        bfs(src);

        if (!vis[dst])
            cout << -1 << endl;
        else
        {
            int dist = 0;
            int node = dst;
            while (parent[node] != -1)
            {
                dist++;
                node = parent[node];
            }
            cout << dist << endl;
        }
    }

    return 0;
}