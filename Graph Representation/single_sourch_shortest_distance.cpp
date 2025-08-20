#include <bits/stdc++.h>
using namespace std;
vector<int> adj_mat[1005];
bool vis[1005];

void bsf(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (auto child : adj_mat[par])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
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
        adj_mat[a].push_back(b);
        adj_mat[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    int src, dst;
    cin >> src >> dst;
    bsf(src);

    cout << (vis[dst] ? "YES" : "NO") << endl;

    return 0;
}