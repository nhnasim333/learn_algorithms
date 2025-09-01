#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
int vis[1005][1005];
pair<int, int> parent[1005][1005];
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;

bool valid(int i, int j)
{
    if (i < 0 || j < 0 || i >= n || j >= m)
        return false;
    return true;
}

bool bfs(int si, int sj, int di, int dj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    parent[si][sj] = {-1, -1};

    while (!q.empty())
    {
        auto [par_i, par_j] = q.front();
        q.pop();

        if (par_i == di && par_j == dj)
            return true;

        for (int d = 0; d < 4; d++)
        {
            int ci = par_i + directions[d].first;
            int cj = par_j + directions[d].second;

            if (valid(ci, cj) && !vis[ci][cj] && (grid[ci][cj] == '.' || grid[ci][cj] == 'D'))
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                parent[ci][cj] = {par_i, par_j};
            }
        }
    }
    return false;
}

void mark_path(int di, int dj, int si, int sj)
{
    int x = di, y = dj;
    while (!(x == si && y == sj))
    {
        if (grid[x][y] != 'D')
            grid[x][y] = 'X';
        auto [px, py] = parent[x][y];
        x = px;
        y = py;
    }
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
            if (grid[i][j] == 'R')
            {
                si = i;
                sj = j;
            }
            if (grid[i][j] == 'D')
            {
                di = i;
                dj = j;
            }
        }
    }

    memset(vis, 0, sizeof(vis));
    if (bfs(si, sj, di, dj))
        mark_path(di, dj, si, sj);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << grid[i][j];
        cout << endl;
    }
    return 0;
}