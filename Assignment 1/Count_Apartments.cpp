#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
int n, m;

bool valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void dfs(int i, int j) {
    vis[i][j] = true;
    for (auto d : directions) {
        int ni = i + d.first, nj = j + d.second;
        if (valid(ni, nj) && !vis[ni][nj] && grid[ni][nj] == '.') {
            dfs(ni, nj);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> grid[i][j];

    memset(vis, false, sizeof(vis));
    int apartments = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!vis[i][j] && grid[i][j] == '.') {
                apartments++;
                dfs(i, j);
            }
        }
    }
    cout << apartments << endl;
    return 0;
}