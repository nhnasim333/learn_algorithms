#include <bits/stdc++.h>
using namespace std;
vector<int> adj_mat[1005];
bool vis[1005];
int level[1005];

void bsf(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;

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
                level[child] = level[par] + 1;
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
    memset(level, -1, sizeof(level));
    int l;
    cin >> l;
    bsf(0);

    vector<int> nodes;
    for (int i = 0; i < n; i++)
    {
        if (level[i] == l)
        {
            nodes.push_back(i);
        }
    }

    sort(nodes.rbegin(), nodes.rend());
    for (auto node : nodes)
    {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}