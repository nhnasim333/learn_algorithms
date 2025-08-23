#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];

int dfs(int src)
{
    vis[src] = true;
    int cnt = 1;
    for (int child : adj_list[src])
        if (!vis[child])
            cnt += dfs(child);
    return cnt;
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
    memset(vis, false, sizeof(vis));
    vector<int> components_sizes;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            int size = dfs(i);
            components_sizes.push_back(size);
        }
    }
    for (int comp : components_sizes)
        cout << comp << " ";
    cout << endl;
    return 0;
}