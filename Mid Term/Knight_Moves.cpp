#include <bits/stdc++.h>
using namespace std;
int vis[105][105];
int level[105][105];
vector<pair<int, int>> directions = {
    {-2, -1}, {-2, +1},
    {-1, -2}, {-1, +2},
    {+1, -2}, {+1, +2},
    {+2, -1}, {+2, +1}
};
int n, m;

bool valid(int i, int j)
{
    return i >= 0 && j >= 0 && i < n && j < m;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;

        for (int i = 0; i < 8; i++)
        {
            int ci = par_i + directions[i].first;
            int cj = par_j + directions[i].second;

            if (valid(ci, cj) && !vis[ci][cj])
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
            }
        }
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        int si, sj, di, dj;
        cin >> si >> sj >> di >> dj;

        memset(vis, 0, sizeof(vis));
        memset(level, -1, sizeof(level));
        bfs(si, sj);

        cout << level[di][dj] << endl;
    }
    return 0;
}