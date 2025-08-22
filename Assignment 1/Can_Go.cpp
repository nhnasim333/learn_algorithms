#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

bool bfs(int si, int sj, int di, int dj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        int par_i = par.first;
        int par_j = par.second;
        q.pop();

        if (par_i == di && par_j == dj)
            return true;

        for (auto d : directions)
        {
            int nx = par_i + d.first, ny = par_j + d.second;
            if (valid(nx, ny) && !vis[nx][ny] && (grid[nx][ny] == '.' || grid[nx][ny] == 'B'))
            {
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    int si = -1, sj = -1, di = -1, dj = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                si = i;
                sj = j;
            }
            if (grid[i][j] == 'B')
            {
                di = i;
                dj = j;
            }
        }
    }

    memset(vis, false, sizeof(vis));

    if (bfs(si, sj, di, dj))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}