#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool visited[1005];

void bfs(int src)
{
    int cnt = 0;
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        cnt++;

        for (int child : adj_list[par])
        {
            if (!visited[child])
            {
                q.push(child);
                visited[child] = true;
            }
        }
    }
    cout << cnt << endl;
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

    memset(visited, false, sizeof(visited));
    int x;
    cin >> x;
    bfs(x);

    return 0;
}