#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;

bool valid(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

int dfs(int si, int sj)
{
    vis[si][sj] = true;
    int area = 1;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + directions[i].first, cj = sj + directions[i].second;
        if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
        {
            area += dfs(ci, cj);
        }
    }
    return area;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> grid[i][j];

    memset(vis, false, sizeof(vis));
    int min_area = INT_MAX;
    bool found = false;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (!vis[i][j] && grid[i][j] == '.')
            {
                int area = dfs(i, j);
                min_area = min(min_area, area);
                found = true;
            }
        }
    }
    if (found)
        cout << min_area << endl;
    else
        cout << -1 << endl;
    return 0;
}